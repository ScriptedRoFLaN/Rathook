cmake_minimum_required(VERSION 3.20.4)

set(NativePrecompiledHeaders 1)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/toolchain.cmake")


#-- Configuration for cunthook based off internal codes
#-- please be careful when editing this section.

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type")
endif()
set(CMAKE_BUILD_TYPE_VALUES "Debug;Release" CACHE INTERNAL "List of supported build")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_BUILD_TYPE_VALUES})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

set(Force_CXX_23B 0 CACHE BOOL "Force 23B as the CXX Standard, useful for disrepancies in compiler and IDE")

project(cunthook VERSION 0.0.1)
if (NOT Force_CXX_23B)
    set(CMAKE_CXX_STANDARD 23)
endif()
add_library(cunthook SHARED "")

set(Visuals_DrawType "IMGUI" CACHE STRING "Target drawing api")
set(DrawTypes "Textmode;No Visuals;Glez;Engine;IMGUI;IMGUI Streamproof" CACHE INTERNAL "Select the drawing api that cunthook should use")
set_property(CACHE Visuals_DrawType PROPERTY STRINGS ${DrawTypes})
set(Visuals_EnforceStreamSafety 1 CACHE BOOL "If a streamsafe drawing method is used, this will remove features that are not streamsafe.")

set(EnableVisuals 1)
set(EnableGlezDrawing 0)
set(EnableEngineDrawing 0)
set(EnableImGuiDrawing 0)
set(ExternalDrawing 0)
set(Textmode 0)

if(Visuals_DrawType STREQUAL "Textmode")
    set(EnableVisuals 0)
    set(Textmode 1)
elseif(Visuals_DrawType STREQUAL "No Visuals")
    set(EnableVisuals 0)
elseif(Visuals_DrawType STREQUAL "Glez")
    set(EnableGlezDrawing 1)
elseif(Visuals_DrawType STREQUAL "Engine")
    set(EnableEngineDrawing 1)
elseif(Visuals_DrawType STREQUAL "IMGUI")
    set(EnableImGuiDrawing 1)
elseif(Visuals_DrawType STREQUAL "IMGUI Streamproof")
    set(EnableImGuiDrawing 1)
    set(ExternalDrawing 1)
endif()
if (NOT ExternalDrawing)
    set(Visuals_EnforceStreamSafety 0)
endif()

set(EnableProfiler 0 CACHE BOOL "Enable Profiler")
set(EnableGUI 1 CACHE BOOL "Enable GUI")
set(EnableIPC 1 CACHE BOOL "Enable IPC")
set(DataPath "/opt/cunthook/data" CACHE FILEPATH "Data location")
set(VACBypass 0 CACHE BOOL "Textmode VAC bypass")
set(EnableTextmodeStdin 0 CACHE BOOL "Textmode Stdin -> Console bridge (EXPERIMENTAL)")
set(EnableWarnings 0 CACHE BOOL "Enable compile warnings")
set(EnableNullNexus 1 CACHE BOOL "Enable NullNexus chat and other features")
set(EnableLogging 1 CACHE BOOL "Enable logging to /tmp/")
set(EnableClip 1 CACHE BOOL "Enable anti electron/chromium freezing")
set(Unity_ZeroKernel 1 CACHE BOOL "Use a unity build for zerokernel files")
if(NOT EnableVisuals)
    set(EnableGUI 0)
endif()


#-- Internal variables implied as "FORCE" by default
#-- don't set these if they are already set anyways.
if (NOT DEFINED Internal_Binarymode)
    set(Internal_Binarymode 0 CACHE INTERNAL "Build cunthook to be used in 'binary mode'")
endif()
if (NOT DEFINED Internal_Symbolized)
    set(Internal_Symbolized 0 CACHE INTERNAL "Build cunthook with symbols so crashes can be sent")
endif()

#-- End of configuration


if (EnableVisuals)
    set(OpenGL_GL_PREFERENCE "LEGACY")
    if (EnableImGuiDrawing)
        find_package(Freetype REQUIRED)
        target_include_directories(cunthook PRIVATE "${FREETYPE_INCLUDE_DIRS}")
        target_link_libraries(cunthook ${FREETYPE_LIBRARIES})
    endif()
endif()

find_package(Git REQUIRED)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/Modules")
find_package(SDL2 REQUIRED)
find_package(Boost 1.76.5 EXACT)
if (NOT ${Boost_FOUND})
    set(BOOST_LIBS_OPTIONAL "" CACHE STRING "Boost libs to be compiled")
    add_subdirectory(Modules/Boost)
    SET (BOOST_ROOT ${CMAKE_BINARY_DIR}/_deps/boost-src)
    find_package(Boost 1.76.5 EXACT)
    include_directories(${Boost_INCLUDE_DIRS})
endif()


#-- These manage the HASH and DATE when you cloned this project
#-- this is used within the watermark ONLY.
execute_process(COMMAND
        "${GIT_EXECUTABLE}" log -1 --pretty=\"%h\"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE GIT_COMMIT_HASH
        ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND
        "${GIT_EXECUTABLE}" log -1 --pretty=\"%ai\"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE GIT_COMMITTER_DATE
        ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE)

set( CMAKE_SKIP_RPATH true )
find_library(ValveLibraryVStdLib NAMES vstdlib PATHS "${PROJECT_SOURCE_DIR}" NO_DEFAULT_PATH)

if(EnableIPC)
    add_subdirectory(Modules/simple-ipc)
    target_link_libraries(cunthook SimpleIPC)
endif()
if(EnableNullNexus)
    add_subdirectory(Modules/libnullnexus)
    target_link_libraries(cunthook libnullnexus)
endif()
if(EnableVisuals)
    if (EnableGlezDrawing)
        add_subdirectory(Modules/libglez)
    endif()
    target_include_directories(cunthook PRIVATE include/visual)
    find_package(SDL2 REQUIRED)
    if(ExternalDrawing)
        add_subdirectory(Modules/libxoverlay)
        target_link_libraries(cunthook xoverlay)
        target_include_directories(cunthook PRIVATE Modules/libxoverlay/include)
    endif()
    target_include_directories(cunthook PRIVATE "${SDL2_INCLUDE_DIR}")
    if (EnableGlezDrawing)
        target_link_libraries(cunthook glez)
    endif()
    if (EnableGlezDrawing)
        find_package(GLEW REQUIRED)
        target_link_libraries(cunthook ${GLEW_LIBRARIES})
    endif()
endif()


#-- These manage both all the settings within this cmake file and
#-- the github HASH and DATE and complie it into a file for c++ to use.
configure_file(Headers/config.h.in ${CMAKE_SOURCE_DIR}/Headers/config.h @ONLY)
configure_file(Headers/version.h.in ${CMAKE_SOURCE_DIR}/Headers/version.h @ONLY)

set(CMAKE_CXX_FLAGS "-m32 -march=native -fexceptions -DNDEBUG")
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-gnu-unique")
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-march=native -rdynamic -ggdb -Og")
if (Internal_Symbolized)
    set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -ggdb -fvisibility=hidden -fvisibility-inlines-hidden")
else()
    set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -s -funroll-loops -fwhole-program -fipa-pta  -fmerge-all-constants -fdevirtualize-at-ltrans -fsched-pressure -fvisibility=hidden -fvisibility-inlines-hidden")
endif()
if (Force_CXX_23B)
    set(CMAKE_CXX_FLAGS "-std=gnu++2b ${CMAKE_CXX_FLAGS}")
endif()

target_compile_definitions(cunthook PRIVATE
        _GLIBCXX_USE_CXX11_ABI=0
        _POSIX=1
        FREETYPE_GL_USE_VAO=1
        RAD_TELEMETRY_DISABLED=1
        LINUX=1
        USE_SDL=1
        _LINUX=1
        POSIX=1
        GNUC=1
        NO_MALLOC_OVERRIDE=1)

target_include_directories(cunthook SYSTEM PRIVATE
        "Modules/Headers/mp/src/mathlib"
        "Modules/Headers/mp/src/public"
        "Modules/Headers/mp/src/common"
        "Modules/Headers/mp/src/public/tier0"
        "Modules/Headers/mp/src/public/tier1"
        "Modules/Headers/mp/src/public/steam"
        "Modules/Headers/mp/src/tier1"
        "Modules/Headers/mp/src")

if(EnableWarnings)
    target_compile_options(cunthook PRIVATE -Wall -Wextra -Wno-unused-parameter -Wno-class-memaccess -Wno-strict-aliasing -Wno-sign-compare)
else()
    target_compile_options(cunthook PRIVATE -w)
endif()
if(Internal_Binarymode)
    target_compile_options(cunthook PRIVATE -march=x86-64)
endif()

target_include_directories(cunthook PRIVATE include Headers/hooks)
target_link_libraries(cunthook ${ValveLibraryVStdLib} ${SDL2_LIBRARY})
set_target_properties(cunthook PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Sources)
add_subdirectory(Headers)
add_subdirectory(Modules)

target_precompile_headers(cunthook PRIVATE "${CMAKE_SOURCE_DIR}/Headers/common.hpp")


#-- This is the Dynamic Library file that gets built based off
#-- all the configurations above and complies them into it.
if (NOT Internal_Symbolized)
    add_custom_command(TARGET cunthook POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:cunthook> "${CMAKE_SOURCE_DIR}/cunthook.so")
else()
    message("Symbolized build")
    set(Internal_Symbolized 0 CACHE INTERNAL "Build cunthook with symbols so crashes can be sent" FORCE)
endif()