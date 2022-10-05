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

    gui::VBoxContainer panel = gui::VBoxContainer("Test VBox");
    panel.bounds.x = 20;
    panel.bounds.y = 20;
    panel.bounds.width = 300;
    panel.bounds.height = 300;
    
    gui::PanelContainer sub1 = gui::PanelContainer("Sub Panel 1");
    sub1.panelColour = RED;
    gui::PanelContainer sub2 = gui::PanelContainer("Sub Panel 2");
    sub2.panelColour = ORANGE;
    gui::PanelContainer sub3 = gui::PanelContainer("Sub Panel 3");
    sub3.panelColour = YELLOW;
    gui::PanelContainer sub4 = gui::PanelContainer("Sub Panel 4");
    sub4.panelColour = BLUE;
    gui::PanelContainer sub5 = gui::PanelContainer("Sub Panel 5");
    sub5.panelColour = GREEN;

    panel.addElement(&sub1);
    panel.addElement(&sub2);
    panel.addElement(&sub3);
    panel.addElement(&sub4);
    panel.addElement(&sub5);

    logMain.debug("Starting Game Loop");
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(bgColor);
        panel.draw();
        EndDrawing();
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
