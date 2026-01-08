//
// Created by connor on 12/17/25.
//

#pragma once
#include <vector>

#include "Gamepad.h"
#include "InputAction.h"
#include "InputEvent.h"
#include "Keyboard.h"
#include "Key.h"
#include "Mouse.h"

namespace Skater {
    class Input {
    public:
        static void Update();

        static void ProcessInputEvent(InputEvent& event);
        static void RegisterAction(InputAction* action);

        static bool IsKeyPressed(Key key);
        static bool IsKeyJustPressed(Key key);
        static bool IsKeyJustReleased(Key key);

        static bool IsMouseButtonPressed(MouseButton button);
        static Vector2 GetMousePosition();

        static bool IsJoystickButtonPressed(JoystickButton button, int8_t gamepadIdx);
        static float GetJoystickAxis(JoystickAxis axis, int8_t gamepadIdx);
    private:
        static constexpr uint8_t MAX_GAMEPADS = 16;

        static inline std::vector<InputAction*> _actions;

        static inline KeyboardState _previousKeyboardState;
        static inline KeyboardState _currentKeyboardState;

        static inline MouseState _previousMouseState;
        static inline MouseState _currentMouseState;

        static inline Gamepad _gamepads[MAX_GAMEPADS];
    };
}
