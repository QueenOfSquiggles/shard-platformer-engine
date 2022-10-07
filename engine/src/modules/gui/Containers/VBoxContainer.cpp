#include "VBoxContainer.hpp"

namespace gui
{
    void VBoxContainer::draw(Rectangle elementBounds, Theme* parentTheme)
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
        // guidelines (double-thick for visibility)
        DrawRectangleLines(e_bounds.x, e_bounds.y, e_bounds.width, e_bounds.height, RED);
        DrawRectangleLines(e_bounds.x-1, e_bounds.y-1, e_bounds.width+2, e_bounds.height+2, RED);

        e_bounds.height = (elementBounds.height - (padding.top + padding.bottom)) - (separation * (elements.size()-1));
        e_bounds.height /= elements.size();

        for(unsigned int i = 0; i < elements.size(); i++)
        {
            elements[i]->draw(e_bounds, theme);
            e_bounds.y += (separation + e_bounds.height);
        }
    }


}