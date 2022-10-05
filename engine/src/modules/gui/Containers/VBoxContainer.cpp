#include "VBoxContainer.hpp"

namespace gui
{
    void VBoxContainer::addElement(GuiElement *element){
        elements.push_back(element);
        
        int totalHeight = bounds.height - (padding.top+padding.bottom) - (separation * (elements.size() - 1));
        for(int i = 0; i < elements.size(); i++)
        {
            Rectangle rect;
            rect.width = bounds.width - (padding.right+padding.left);
            rect.x = bounds.x + padding.right;

            rect.height = totalHeight / elements.size();
            rect.y = bounds.y + padding.top + rect.height * i + (separation * (i));
            elements[i]->bounds = rect;
        }
    }
}
