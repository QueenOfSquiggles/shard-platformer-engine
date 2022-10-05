#pragma once
#include <raylib.h>
#include <string>
#include "../logging/Log.hpp"

using namespace std;

namespace gui
{

    struct Padding {
        int left;
        int right;
        int top;
        int bottom;
    };

    class GuiElement
    {
    protected:
        logging::Log guiLog = logging::Log("GUI");
    public:
        string name;
        Rectangle bounds;

        GuiElement(string m_name) {name = m_name;}
        bool visible = true;
        virtual void draw(){
            // this prints because we really don't want to be drawing plain GuiElements. This shouldn't be called at any point
            guiLog.debug("Drawing debug Gui Element: " + name);
            DrawRectangle(bounds.x, bounds.y, bounds.width, bounds.height, PURPLE);
        }
    };
}