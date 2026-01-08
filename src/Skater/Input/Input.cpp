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
            case InputEventType::JoystickUpdated:
                break;
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
}
