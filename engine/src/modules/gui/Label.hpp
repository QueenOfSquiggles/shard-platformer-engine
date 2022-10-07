#pragma once
#include "GuiElement.hpp"

namespace gui
{
    class Label : public GuiElement
    {
    public:
        Label(string m_name) : GuiElement(m_name)
        {
            text = m_name;
        }
        string text = "Example Text";
        
        Padding bgPadding;
        int fontSize = 18;

        virtual void draw(Rectangle bounds, Theme* parentTheme) override
        {
            DrawRectangle(bounds.x, bounds.y, bounds.width, fontSize+2, getThemeProp(parentTheme, "label:bg", BLACK));
            DrawText(text.c_str(), bounds.x+5, bounds.y, fontSize, getThemeProp(parentTheme, "label:font_col", WHITE));
        }


    };


}