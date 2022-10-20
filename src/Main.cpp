/**
 * @file Main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define RAYGUI_IMPLEMENTATION


#include "modules/lua/LuaSystems.hpp"
#include "modules/logging/Log.hpp"
#include "modules/io/IO.hpp"

#include <iostream>
#include <string>
#include <raylib.h>
#include <raymath.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui/raygui.h>

logging::Log logMain = logging::Log("MAIN");

void tracebackIntermediary(int msgType, const char* msg, va_list args)
{
    std::string modifiedMsg = "[RAYLIB]" + std::string(msg);
    logMain.raylibLogCallback(msgType, modifiedMsg.c_str(), args);
}

int main()
{

    SetTraceLogCallback(tracebackIntermediary);

    logMain.debug("Creating window");
    InitWindow(800, 450, "Test Window");
    SetTargetFPS(60);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Vector2 scroll_target;
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        Rectangle rect = GuiScrollPanel((Rectangle){0,0,200, 300}, "A scroll panel", (Rectangle){0, 0, 200, 600}, &scroll_target);
        if(GuiLabelButton((Rectangle){rect.x, rect.y, 60, 20}, "This is a button!"))
        {
            logMain.debug("Button was pressed <3");
        }
        EndDrawing();

    }

    logMain.debug("Closing window and performing cleanup");
    CloseWindow();

    return 0;
}

