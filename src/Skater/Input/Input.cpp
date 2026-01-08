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
