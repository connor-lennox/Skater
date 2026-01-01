//
// Created by connor on 12/17/25.
//

#include "Skater/Input/Keyboard.h"

namespace Skater {
    KeyboardState Keyboard::GetState() {
        // Return a copy of our internal current state
        return { _currentState };
    }

    void Keyboard::SetKey(const Keys key) {
        _currentState.SetKey(key);
    }

    void Keyboard::ClearKey(const Keys key) {
        _currentState.ClearKey(key);
    }
}
