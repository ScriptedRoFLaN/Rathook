target_sources(cunthook PRIVATE
	"${CMAKE_CURRENT_LIST_DIR}/astar.h"
	"${CMAKE_CURRENT_LIST_DIR}/CNavFile.h"
	"${CMAKE_CURRENT_LIST_DIR}/nav.h")

target_include_directories(cunthook PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
