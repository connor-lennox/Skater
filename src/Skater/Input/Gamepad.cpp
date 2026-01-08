//
// Created by connor on 1/8/26.
//

#include "Skater/Input/Gamepad.h"

namespace Skater {
    GamepadState Gamepad::GetState() {
        return { _currentState };
    }

    void Gamepad::UpdateState(const GamepadState &state) {
        _previousState = _currentState;
        _currentState = state;
    }

    void Gamepad::SetButton(const JoystickButton button) {
        _currentState.SetButton(button);
    }

    void Gamepad::ClearButton(const JoystickButton button) {
        _currentState.ClearButton(button);
    }


    float GamepadState::GetAxis(const JoystickAxis axis) const {
        switch (axis) {
            case JoystickAxis::None:
                return 0.0f;
            case JoystickAxis::LeftStickRight:
                return _leftThumbstick.X > 0 ? _leftThumbstick.X : 0;
            case JoystickAxis::LeftStickLeft:
                return _leftThumbstick.X < 0 ? -_leftThumbstick.X : 0;
            case JoystickAxis::LeftStickUp:
                return _leftThumbstick.Y < 0 ? -_leftThumbstick.Y : 0;
            case JoystickAxis::LeftStickDown:
                return _leftThumbstick.Y > 0 ? _leftThumbstick.Y : 0;
            case JoystickAxis::RightStickRight:
                return _rightThumbstick.X > 0 ? _rightThumbstick.X : 0;
            case JoystickAxis::RightStickLeft:
                return _rightThumbstick.X < 0 ? -_rightThumbstick.X : 0;
            case JoystickAxis::RightStickUp:
                return _rightThumbstick.Y < 0 ? -_rightThumbstick.Y : 0;
            case JoystickAxis::RightStickDown:
                return _rightThumbstick.Y > 0 ? _rightThumbstick.Y : 0;
            case JoystickAxis::LeftTrigger:
                return _leftTrigger;
            case JoystickAxis::RightTrigger:
                return _rightTrigger;
            default:
                return 0.0f;
        }
    }

    bool GamepadState::GetButton(const JoystickButton button) const {
        if (button == JoystickButton::None) {
            return false;
        }
        return (_buttonMask & 1 << (static_cast<int>(button) - 1)) != 0;
    }

    void GamepadState::SetButton(JoystickButton button) {
        if (button == JoystickButton::None) {
            return;
        }
        _buttonMask |= 1 << static_cast<int>(button) - 1;
    }

    void GamepadState::ClearButton(JoystickButton button) {
        if (button == JoystickButton::None) {
            return;
        }
        _buttonMask &= ~(1 << static_cast<int>(button) - 1);
    }
}
