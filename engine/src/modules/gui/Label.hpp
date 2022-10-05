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
        
        Color bgColour = BLACK;
        Color fontColour = WHITE;
        Padding bgPadding;
        int fontSize = 12;

        virtual void draw() override
        {
            DrawRectangle(bounds.x, bounds.y, bounds.width, bounds.height, bgColour);
            DrawText(text.c_str(), bounds.x, bounds.y, fontSize, fontColour);
        }


    };


}