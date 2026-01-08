//
// Created by connor on 1/8/26.
//

#pragma once
#include "JoystickAxis.h"
#include "JoystickButton.h"
#include "Skater/Math/Vector2.h"

namespace Skater {
    class GamepadState {
    public:
        GamepadState() = default;
        GamepadState(const GamepadState &obj) = default;

        [[nodiscard]] float GetAxis(JoystickAxis axis) const;
        [[nodiscard]] bool GetButton(JoystickButton button) const;

        void SetLeftThumbstick(const Vector2 value) { _leftThumbstick = value; }
        void SetRightThumbstick(const Vector2 value) { _rightThumbstick = value; }
        void SetLeftTrigger(const float value) { _leftTrigger = value; }
        void SetRightTrigger(const float value) { _rightTrigger = value; }

        void SetButton(JoystickButton button);
        void ClearButton(JoystickButton button);
    private:
        Vector2 _leftThumbstick = Vector2::Zero;
        Vector2 _rightThumbstick = Vector2::Zero;
        float _leftTrigger = 0;
        float _rightTrigger = 0;
        uint16_t _buttonMask = 0;
    };

    class Gamepad {
    public:
        GamepadState GetState();
        void UpdateState(const GamepadState &state);

        [[nodiscard]] bool GetButton(const JoystickButton button) const { return _currentState.GetButton(button); }
        [[nodiscard]] float GetAxis(const JoystickAxis axis) const { return _currentState.GetAxis(axis); }

        void SetButton(JoystickButton button);
        void ClearButton(JoystickButton button);
    private:
        GamepadState _currentState;
        GamepadState _previousState;
    };
}
