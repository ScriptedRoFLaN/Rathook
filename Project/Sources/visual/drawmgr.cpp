#include <MiscTemporary.hpp>
#include <hacks/Aimbot.hpp>
#include <hacks/hacklist.hpp>
#if ENABLE_IMGUI_DRAWING
#include "imgui/imrenderer.hpp"
#elif ENABLE_GLEZ_DRAWING
#include <glez/glez.hpp>
#include <glez/record.hpp>
#include <glez/draw.hpp>
#endif
#include <settings/Bool.hpp>
#include <settings/Float.hpp>
#include <menu/GuiInterface.hpp>
#include "common.hpp"
#include "visual/drawing.hpp"
#include "hack.hpp"
#include "menu/menu/Menu.hpp"
#include "drawmgr.hpp"

static settings::Boolean info_text{ "hack-info.enable", "true" };
static settings::Boolean info_text_min{ "hack-info.minimal", "false" };

void render_cheat_visuals() {
    BeginCheatVisuals();
    DrawCheatVisuals();
    EndCheatVisuals();
}

#if ENABLE_GLEZ_DRAWING
glez::record::Record bufferA{};
glez::record::Record bufferB{};
glez::record::Record *buffers[] = { &bufferA, &bufferB };
#endif

int currentBuffer = 0;

void BeginCheatVisuals() {
#if ENABLE_IMGUI_DRAWING
    im_renderer::bufferBegin();
#elif ENABLE_GLEZ_DRAWING
    buffers[currentBuffer]->begin();
#endif
    ResetStrings();
}


double getRandom(double lower_bound, double upper_bound) {
    std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
    static std::mt19937 rand_engine(std::time(nullptr));

    double x = unif(rand_engine);
    return x;
}

void DrawCheatVisuals() {
    std::string name_s, reason_s;

    if (info_text) {
        auto color = colors::CuntBlue;
        color.a    = 1.0f;

        AddSideString("Cunthook by Blue Snoop", color);

        if (!info_text_min) {
            AddSideString("The best linux cheat right next to cathook.", colors::gui);
        }
    }

    EC::run(EC::Draw);

    if (CE_GOOD(g_pLocalPlayer->entity) && !g_Settings.bInvalid) {
        Prediction_PaintTraverse();
    }

    DrawStrings();

#if ENABLE_GUI
    gui::draw();
#endif
}

void EndCheatVisuals() {
#if ENABLE_GLEZ_DRAWING
    buffers[currentBuffer]->end();
#endif
#if ENABLE_GLEZ_DRAWING || ENABLE_IMGUI_DRAWING
    currentBuffer = !currentBuffer;
#endif
}

void DrawCache() {
#if ENABLE_GLEZ_DRAWING
    buffers[!currentBuffer]->replay();
#endif
}
