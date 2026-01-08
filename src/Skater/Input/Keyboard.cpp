//
// Created by connor on 12/17/25.
//

#include "Skater/Input/Keyboard.h"

namespace Skater {
    KeyboardState Keyboard::GetState() {
        // Return a copy of our internal current state
        return { _currentState };
    }

    void Keyboard::SetKey(const Key key) {
        _currentState.SetKey(key);
    }

    void Keyboard::ClearKey(const Key key) {
        _currentState.ClearKey(key);
    }


    KeyboardState::KeyboardState() {
        _state0 = 0;
        _state1 = 0;
        _state2 = 0;
        _state3 = 0;
        _state4 = 0;
        _state5 = 0;
        _state6 = 0;
        _state7 = 0;
    }

    KeyboardState::KeyboardState(const KeyboardState &obj) {
        _state0 = obj._state0;
        _state1 = obj._state1;
        _state2 = obj._state2;
        _state3 = obj._state3;
        _state4 = obj._state4;
        _state5 = obj._state5;
        _state6 = obj._state6;
        _state7 = obj._state7;
    }

    bool KeyboardState::GetKey(const Key key) const {
        if (key == Key::None) {
            return false;
        }

        const auto keyVal = static_cast<int>(key);

        const uint32_t mask = 1 << (keyVal & 0x1f);

        uint32_t val = 0;
        switch (keyVal >> 5) {
            case 0: val = _state0; break;
            case 1: val = _state1; break;
            case 2: val = _state2; break;
            case 3: val = _state3; break;
            case 4: val = _state4; break;
            case 5: val = _state5; break;
            case 6: val = _state6; break;
            case 7: val = _state7; break;
            default: break;
        }
        return (val & mask) != 0;
    }

    void KeyboardState::SetKey(const Key key) {
        if (key == Key::None) {
            return;
        }

        const auto keyVal = static_cast<int>(key);

        const uint32_t mask = 1 << (keyVal & 0x1f);

        switch (keyVal >> 5) {
            case 0: _state0 |= mask; break;
            case 1: _state1 |= mask; break;
            case 2: _state2 |= mask; break;
            case 3: _state3 |= mask; break;
            case 4: _state4 |= mask; break;
            case 5: _state5 |= mask; break;
            case 6: _state6 |= mask; break;
            case 7: _state7 |= mask; break;
            default: break;
        }
    }

    void KeyboardState::ClearKey(const Key key) {
        if (key == Key::None) {
            return;
        }

        const auto keyVal = static_cast<int>(key);

        const uint32_t mask = 1 << (keyVal & 0x1f);

        switch (keyVal >> 5) {
            case 0: _state0 &= ~mask; break;
            case 1: _state1 &= ~mask; break;
            case 2: _state2 &= ~mask; break;
            case 3: _state3 &= ~mask; break;
            case 4: _state4 &= ~mask; break;
            case 5: _state5 &= ~mask; break;
            case 6: _state6 &= ~mask; break;
            case 7: _state7 &= ~mask; break;
            default: break;
        }
    }
}
