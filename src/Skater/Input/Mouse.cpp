//
// Created by connor on 1/7/26.
//

#include "Skater/Input/Mouse.h"

namespace Skater {
    MouseState Mouse::GetState() {
        return { _currentState };
    }

    void Mouse::SetPosition(const Vector2 position) {
        _currentState.SetPosition(position);
    }

    void Mouse::SetButton(const MouseButton button) {
        _currentState.SetButton(button);
    }

    void Mouse::ClearButton(const MouseButton button) {
        _currentState.ClearButton(button);
    }


    void MouseState::SetPosition(const Vector2 position) {
        _currentPosition = position;
    }

    void MouseState::SetButton(MouseButton button) {
        if (button == MouseButton::None) {
            return;
        }
        _buttonMask |= 1 << static_cast<int>(button) - 1;
    }

    void MouseState::ClearButton(MouseButton button) {
        if (button == MouseButton::None) {
            return;
        }
        _buttonMask &= ~(1 << static_cast<int>(button) - 1);
    }

    bool MouseState::GetButton(MouseButton button) const {
        if (button == MouseButton::None) {
            return false;
        }
        return _buttonMask & 1 << (static_cast<int>(button) - 1) > 0;
    }

}
