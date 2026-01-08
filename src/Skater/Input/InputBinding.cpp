//
// Created by connor on 1/7/26.
//

#include "Skater/Input/InputBinding.h"

#include "Skater/Input/Input.h"

namespace Skater {
    KeyInputBinding::KeyInputBinding(const Key key) : _key(key) {}
    float KeyInputBinding::GetValue() {
        return Input::IsKeyPressed(_key) ? 1.0 : 0.0;
    }

    MouseButtonInputBinding::MouseButtonInputBinding(const MouseButton button) : _button(button) {}
    float MouseButtonInputBinding::GetValue() {
        return Input::IsMouseButtonPressed(_button) ? 1.0 : 0.0;
    }

    JoystickButtonInputBinding::JoystickButtonInputBinding(const JoystickButton button, const int8_t gamepadIdx) : _button(button), _gamepadIdx(gamepadIdx) {}
    float JoystickButtonInputBinding::GetValue() {
        return Input::IsJoystickButtonPressed(_button, _gamepadIdx) ? 1.0 : 0.0;
    }

    JoystickAxisInputBinding::JoystickAxisInputBinding(const JoystickAxis axis, const int8_t gamepadIdx) : _axis(axis), _gamepadIdx(gamepadIdx) {}
    float JoystickAxisInputBinding::GetValue() {
        return Input::GetJoystickAxis(_axis, _gamepadIdx);
    }
}
