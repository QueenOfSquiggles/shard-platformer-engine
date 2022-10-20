#pragma once
#include <raylib.h>

namespace input
{
    class InputAdapter
    {

    public:
        InputAdapter()
        {
            // connect callbacks   
        }

        Vector2 getMousePos() { return GetMousePosition(); }
        Vector2 getMouseDelta() { return GetMouseDelta(); }
        float getMouseWheel() { return GetMouseWheelMove(); }
        bool isGamepadConnected() {return IsGamepadAvailable(0); }
        bool getGamepadButton(int button) { return GetGamepadButtonPressed() == button; }
    };
}