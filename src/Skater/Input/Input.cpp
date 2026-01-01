//
// Created by connor on 12/17/25.
//

#include "Skater/Input/Input.h"

#include "Skater/Input/Keyboard.h"

namespace Skater {
    void Input::Update() {
        _previousState = _currentState;
        _currentState = Keyboard::GetState();
    }

    bool Input::IsKeyPressed(const Keys key) {
        return _currentState.GetKey(key);
    }

    bool Input::IsKeyJustPressed(const Keys key) {
        return _currentState.GetKey(key) && !_previousState.GetKey(key);
    }

    bool Input::IsKeyJustReleased(const Keys key) {
        return !_currentState.GetKey(key) && _previousState.GetKey(key);
    }
}
