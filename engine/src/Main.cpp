#define RAYGUI_IMPLEMENTATION


#include "modules/lua/LuaSystems.hpp"
#include "modules/logging/Log.hpp"
#include "modules/io/IO.hpp"
#include "modules/gui/Containers/VBoxContainer.hpp"

#include <iostream>
#include <string>
#include <raymath.h>

int lua_set_window_name(lua_State* state);
int lua_set_bg_colour(lua_State* state);

Color bgColor = BLACK;
logging::Log logMain = logging::Log("MAIN");

void tracebackIntermediary(int msgType, const char* msg, va_list args);

int main()
{

    SetTraceLogCallback(tracebackIntermediary);

    logMain.debug("Creating window");
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Test Window");
    SetTargetFPS(60);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    

    logMain.debug("Testing panel container GUI elements");

    gui::Theme theme;
    theme.addProperty("panel_container:bg", WHITE);
    theme.addProperty("panel_container:border", BLACK);
    theme.addProperty("label:bg", GRAY);
    theme.addProperty("label:font_col", WHITE);

    gui::VBoxContainer panel = gui::VBoxContainer("Test VBox");
    
    logMain.debug("Starting Game Loop");
    gui::Padding windowPadding = (gui::Padding){30, 30, 30, 30};
    Rectangle screenBounds;
    screenBounds.x = windowPadding.left;
    screenBounds.y = windowPadding.top;
    screenBounds.width = GetScreenWidth() - (windowPadding.right + windowPadding.left);
    screenBounds.height = GetScreenHeight() - (windowPadding.top + windowPadding.bottom);

    int panelNum = 0;
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(theme.getProperty("main:bg", BLACK));
        panel.draw(screenBounds, &theme);
        EndDrawing();
        if (IsWindowResized())
        {
            screenBounds.width = GetScreenWidth() - (windowPadding.right + windowPadding.left);
            screenBounds.height = GetScreenHeight() - (windowPadding.top + windowPadding.bottom);
        }
        int kpID = GetKeyPressed();
        if(kpID == KEY_ENTER)
        {
            logMain.debug("Enter was pressed! Adding panel");
            gui::PanelContainer *subPanel = new gui::PanelContainer("P #" + to_string(panelNum++));
            panel.addElement(subPanel);
        }else if(kpID == KEY_BACKSPACE && panel.getElementCount() > 0)
        {
            logMain.debug("Backspace was pressed! removing panel");
            panel.removeElement(panel.getElementCount()-1);
            panelNum--;
        }
    }

    logMain.debug("Closing window and performing cleanup");
    CloseWindow();

    return 0;
}

int lua_set_window_name(lua_State* state)
{
    int argc = lua_gettop(state);
    if (argc <= 0)
    {
        // too few arguments!
        lua_pushboolean(state, false);
        return 1;
    }
    const char* n_title = lua_tostring(state, 1);

    SetWindowTitle(n_title);
    lua_pushboolean(state, true);
    return 1;
}

int lua_set_bg_colour(lua_State* state)
{
    int argc = lua_gettop(state);
    if (argc < 3)
    {
        // too few arguments!
        lua_pushboolean(state, false);
        return 1;
    }
    double r = lua_tonumber(state, 1);
    double g = lua_tonumber(state, 2);
    double b = lua_tonumber(state, 3);
    Vector4 colourVec = Vector4();
    colourVec.x = r;
    colourVec.y = g;
    colourVec.z = b;
    colourVec.w = 1.0;
    
    if (argc > 3)
    {
        double a = lua_tonumber(state, 4);
        colourVec.w = a;
    }
    bgColor = ColorFromNormalized(colourVec);
    lua_pushboolean(state, true);
    return 1;
}

void tracebackIntermediary(int msgType, const char* msg, va_list args)
{
    std::string modifiedMsg = "[RAYLIB]" + std::string(msg);
    logMain.raylibLogCallback(msgType, modifiedMsg.c_str(), args);
}
