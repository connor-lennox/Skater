//
// Created by connor on 12/17/25.
//

#include "Skater/Input/Input.h"

#include "Skater/Input/Keyboard.h"

namespace Skater {
    void Input::Update() {
        _previousKeyboardState = _currentKeyboardState;
        _currentKeyboardState = Keyboard::GetState();

        _previousMouseState = _currentMouseState;
        _currentMouseState = Mouse::GetState();

        for (const auto action : _actions) {
            action->Update();
        }
    }

    void Input::ProcessInputEvent(InputEvent &event) {
        switch (event.GetEventType()) {
            case InputEventType::None:
                break;
            case InputEventType::KeyPressed: {
                const auto keyPressEvent = dynamic_cast<KeyPressedInputEvent &>(event);
                Keyboard::SetKey(keyPressEvent.GetKey());
                break;
            }
            case InputEventType::KeyReleased: {
                const auto keyReleaseEvent = dynamic_cast<KeyReleasedInputEvent &>(event);
                Keyboard::ClearKey(keyReleaseEvent.GetKey());
                break;
            }
            case InputEventType::MouseButtonPressed: {
                const auto mousePressEvent = dynamic_cast<MouseButtonPressedInputEvent &>(event);
                Mouse::SetButton(mousePressEvent.GetMouseButton());
                break;
            }
            case InputEventType::MouseButtonReleased: {
                const auto mouseReleaseEvent = dynamic_cast<MouseButtonReleasedInputEvent &>(event);
                Mouse::ClearButton(mouseReleaseEvent.GetMouseButton());
                break;
            }
            case InputEventType::MouseMoved: {
                const auto mouseMoveEvent = dynamic_cast<MouseMovedInputEvent &>(event);
                Mouse::SetPosition(mouseMoveEvent.GetMousePosition());
                break;
            }
            case InputEventType::MouseScrolled:
                break;
            case InputEventType::JoystickUpdated: {
                const auto joystickEvent = dynamic_cast<JoystickUpdatedInputEvent &>(event);
                const auto idx = joystickEvent.GetGamepadIdx();
                if (idx >= MAX_GAMEPADS) {
                    break;
                }
                _gamepads[idx].UpdateState(joystickEvent.GetGamepadState());
                break;
            }
            default: break;
        }
    }

    void Input::RegisterAction(InputAction* action) {
        _actions.push_back(action);
    }

    bool Input::IsKeyPressed(const Key key) {
        return _currentKeyboardState.GetKey(key);
    }

    bool Input::IsKeyJustPressed(const Key key) {
        return _currentKeyboardState.GetKey(key) && !_previousKeyboardState.GetKey(key);
    }

    bool Input::IsKeyJustReleased(const Key key) {
        return !_currentKeyboardState.GetKey(key) && _previousKeyboardState.GetKey(key);
    }

    bool Input::IsMouseButtonPressed(const MouseButton button) {
        return _currentMouseState.GetButton(button);
    }

    Vector2 Input::GetMousePosition() {
        return _currentMouseState.GetPosition();
    }

    bool Input::IsJoystickButtonPressed(const JoystickButton button, const int8_t gamepadIdx) {
        // "Any joystick" - returns true if any are true
        if (gamepadIdx == -1) {
            for (auto gamepad : _gamepads) {
                if (gamepad.GetButton(button)) {
                    return true;
                }
            }
            return false;
        }

        if (gamepadIdx >= MAX_GAMEPADS) {
            return false;
        }

        return _gamepads[gamepadIdx].GetButton(button);
    }

    float Input::GetJoystickAxis(const JoystickAxis axis, const int8_t gamepadIdx) {
        // "Any joystick" - returns max value
        if (gamepadIdx == -1) {
            auto val = 0.0f;
            for (auto gamepad : _gamepads) {
                val = std::max(val, gamepad.GetAxis(axis));
            }
            return val;
        }

        if (gamepadIdx >= MAX_GAMEPADS) {
            return 0.0f;
        }

        return _gamepads[gamepadIdx].GetAxis(axis);
    }
}
