#include "PanelContainer.hpp"

namespace gui
{
    void PanelContainer::draw()
    {
        if (!visible) return;
        DrawRectangle(bounds.x, bounds.y, bounds.width, bounds.height, panelColour);
        panelLabel.draw();
        for(GuiElement *gel : elements)
        {
            gel->draw();
        }
    }

    void PanelContainer::addElement(GuiElement *element)
    {
        Rectangle e_bounds = bounds;
        e_bounds.x += padding.left;
        e_bounds.y += padding.top;
        e_bounds.width -= (padding.left + padding.right);
        e_bounds.height -= (padding.top + padding.bottom);
        element->bounds = e_bounds;

        elements.push_back(element);

        guiLog.debug("Adding contained element " + element->name + " to " + name + ". Now containing : " + to_string(elements.size()) + " element");
    }
}