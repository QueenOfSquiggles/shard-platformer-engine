#include "PanelContainer.hpp"

namespace gui
{
    void PanelContainer::draw(Rectangle elementBounds, Theme* parentTheme)
    {
        if (!visible) return;
        Theme* theme = getTheme(parentTheme);
        DrawRectangle(elementBounds.x, elementBounds.y, elementBounds.width, elementBounds.height, theme->getProperty("panel_container:bg", WHITE));
        DrawRectangleLines(elementBounds.x, elementBounds.y, elementBounds.width, elementBounds.height, theme->getProperty("panel_container:border", BLACK));
        panelLabel.draw(elementBounds, theme);
        Rectangle e_bounds = elementBounds;
        e_bounds.x += padding.left;
        e_bounds.y += padding.top;
        e_bounds.width -= (padding.left + padding.right);
        e_bounds.height -= (padding.top + padding.bottom);
        for(GuiElement *gel : elements)
        {
            gel->draw(e_bounds, theme);
        }
    }
}