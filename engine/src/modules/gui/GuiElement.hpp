#pragma once
#include <raylib.h>
#include <string>
#include "../logging/Log.hpp"
#include "Theme.hpp"

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
        Theme *theme = nullptr;
    protected:
        logging::Log guiLog = logging::Log("GUI");

        Theme* getTheme(Theme *parentTheme) { if (theme == nullptr) return parentTheme; else return theme; }

        Color getThemeProp(Theme* parentTheme, string propertyName) { return getThemeProp(parentTheme, propertyName, PINK); } 

        Color getThemeProp(Theme* parentTheme, string propertyName, Color defaultColour) 
        {
            Theme* t = getTheme(parentTheme);
            return t->getProperty(propertyName, defaultColour);
        }
    public:

        ~GuiElement(){
            delete(theme);
        }
        string name;
        Rectangle bounds;

        GuiElement(string m_name) {name = m_name;}
        bool visible = true;
        virtual void draw(Rectangle elementBounds, Theme *parentTheme){
            // this prints because we really don't want to be drawing plain GuiElements. This shouldn't be called at any point
            guiLog.debug("Drawing debug Gui Element: " + name);
            Theme *curTheme = getTheme(parentTheme);
            DrawRectangle(elementBounds.x, elementBounds.y, elementBounds.width, elementBounds.height, curTheme->getProperty("default_panel:bg", PINK));
        }
        void setTheme(Theme *n_theme) { theme = n_theme; }

    };
}