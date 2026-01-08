//
// Created by connor on 12/17/25.
//

#pragma once

#include <cstdint>

#include "Key.h"

namespace Skater {
    /// Current state of keyboard, represented as a 256-bit bitmask
    class KeyboardState {
    public:
        /// Default constructor
        KeyboardState ();

        /// Copy constructor
        KeyboardState (const KeyboardState &obj);

        void SetKey(Key key);
        void ClearKey(Key key);
        [[nodiscard]] bool GetKey(Key key) const;

    private:
        uint32_t _state0 = 0, _state1 = 0, _state2 = 0, _state3 = 0, _state4 = 0, _state5 = 0, _state6 = 0, _state7 = 0;
    };

    class Keyboard {
    public:
        static KeyboardState GetState();

        static void SetKey(Key key);
        static void ClearKey(Key key);
    private:
        static inline KeyboardState _currentState;
    };
}
