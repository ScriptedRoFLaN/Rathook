#include <menu/BaseMenuObject.hpp>
#include <menu/wm/WindowHeader.hpp>
#include <menu/wm/WMWindow.hpp>
#include <menu/Menu.hpp>
#include <menu/Message.hpp>

/*
  Created on 06.07.18.
*/
namespace zerokernel_windowheader
{
static settings::RVariable<rgba_t> color_background{ "zk.style.window-header.color.background.inactive", "00000000" };
static settings::RVariable<rgba_t> color_background_focused{ "zk.style.window-header.color.background.active", "446498ff" };
static settings::RVariable<rgba_t> color_border{ "zk.style.window-header.color.border.inactive", "446498ff" };
static settings::RVariable<rgba_t> color_border_focused{ "zk.style.window-header.color.border.active", "446498ff" };
} // namespace zerokernel_windowheader

zerokernel::WindowHeader::WindowHeader(WMWindow &window) : BaseMenuObject(), window(window)
{
    setParent(&window);

    bb.width.mode = BoundingBox::SizeMode::Mode::FILL;
    bb.height.setContent();

    auto title  = std::make_unique<Text>();
    this->title = title.get();
    title->bb.setPadding(4.5, 4.5, 5, 0);
    title->bb.width.setContent();
    title->bb.height.setContent();
    printf("Title: %p\n", this->title);
    addObject(std::move(title));
}

bool zerokernel::WindowHeader::handleSdlEvent(SDL_Event *event)
{
    if (Container::handleSdlEvent(event))
        return true;

    if (isHovered() && event->type == SDL_MOUSEBUTTONDOWN)
    {
        dragged = true;
        return true;
    }
    if (event->type == SDL_MOUSEBUTTONUP)
    {
        dragged = false;
    }
    return false;
}

void zerokernel::WindowHeader::render()
{
    renderBackground(window.isFocused() ? *zerokernel_windowheader::color_background_focused : *zerokernel_windowheader::color_background);
    renderBorder(window.isFocused() ? *zerokernel_windowheader::color_border_focused : *zerokernel_windowheader::color_border);

    Container::render();
}

void zerokernel::WindowHeader::update()
{
    Container::update();

    if (dragged)
    {
        window.move(window.xOffset + Menu::instance->dx, window.yOffset + Menu::instance->dy);
    }
}

void zerokernel::WindowHeader::handleMessage(zerokernel::Message &msg, bool is_relayed)
{
    BaseMenuObject::handleMessage(msg, is_relayed);

    if (!is_relayed)
    {
        if (msg.name == "LeftClick")
        {
            window.requestClose();
        }
    }
}

void zerokernel::WindowHeader::updateTitle()
{
    title->set(window.name);
}

void zerokernel::WindowHeader::reorderElements()
{
    title->move(0, 0);
}

bool zerokernel::WindowHeader::isHidden()
{
    return BaseMenuObject::isHidden() || !window.shouldDrawHeader();
}
