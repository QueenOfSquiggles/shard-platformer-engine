#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <string>

#include "modules/lua/LuaSystems.hpp"

int lua_set_window_name(lua_State* state);
int lua_set_bg_colour(lua_State* state);
bool match_str(std::string str1, std::string str2);

Color bgColor = RAYWHITE;

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Test Window");
    SetTargetFPS(60);

    lua::LuaManager luaMan;
    luaMan.createNewState(true);
    luaMan.registerMethod("set_title", lua_set_window_name);
    luaMan.registerMethod("set_bg_colour", lua_set_bg_colour);
    luaMan.loadFile("./demo.lua");
    luaMan.executeState();
    //luaMan.executeLuaString("test_call()");
    luaMan.close();
    
    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(bgColor);
        DrawText("This is a change in the codebase", 10, 10, 20, BLACK);

        EndDrawing();
    }


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

bool match_str(std::string str1, std::string str2)
{
    return false;
}