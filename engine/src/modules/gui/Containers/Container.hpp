#pragma once
#include <vector>
#include "../GuiElement.hpp"

namespace gui
{
    class Container : public GuiElement
    {
    protected:
        vector<GuiElement*> elements;
    public:
        Container(string m_name) : GuiElement(m_name){}
        
        virtual void addElement(GuiElement *element)
        {
            elements.push_back(element);
        }

        int getElementCount()
        {
            return elements.size();
        }

        GuiElement* getElement(int index)
        {
            return elements[index];
        }

        void removeElement(int index)
        {
            elements.erase(elements.begin() + index);
        }
    };


}