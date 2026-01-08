//
// Created by connor on 12/17/25.
//

#pragma once
#include <vector>

#include "InputAction.h"
#include "Keyboard.h"
#include "Key.h"
#include "Mouse.h"

namespace Skater {
    class Input {
    public:
        static void Update();

        static void RegisterAction(InputAction* action);

        static bool IsKeyPressed(Key key);
        static bool IsKeyJustPressed(Key key);
        static bool IsKeyJustReleased(Key key);

        static bool IsMouseButtonPressed(MouseButton button);
        static Vector2 GetMousePosition();
    private:
        static inline std::vector<InputAction*> _actions;

        static inline KeyboardState _previousKeyboardState;
        static inline KeyboardState _currentKeyboardState;

        static inline MouseState _previousMouseState;
        static inline MouseState _currentMouseState;
    };
}
