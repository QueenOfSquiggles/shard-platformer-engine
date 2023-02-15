#pragma once
#include <raylib.h>

namespace input
{
    class InputAdapter
    {

    
    public:
    
        static InputAdapter* singleton;
        InputAdapter()
        {
            // connect callbacks
            singleton = this;
        }
        ~InputAdapter()
        {}

        inline Vector2 getMousePos() { return GetMousePosition(); }
        inline Vector2 getMouseDelta() { return GetMouseDelta(); }
        inline float getMouseWheel() { return GetMouseWheelMove(); }
        inline bool isGamepadConnected() {return IsGamepadAvailable(0); }
        inline bool getGamepadButton(int button) { return GetGamepadButtonPressed() == button; }
    };
}