//
// Created by connor on 12/17/25.
//

#pragma once
#include <cstdint>

#include "Keys.h"

namespace Skater {
    /// Current state of keyboard, represented as a 256-bit bitmask
    class KeyboardState {
    public:
        /// Default constructor
        KeyboardState ();

        /// Copy constructor
        KeyboardState (const KeyboardState &obj);

        void SetKey(Keys key);
        void ClearKey(Keys key);
        [[nodiscard]] bool GetKey(Keys key) const;

    private:
        uint32_t _state0 = 0, _state1 = 0, _state2 = 0, _state3 = 0, _state4 = 0, _state5 = 0, _state6 = 0, _state7 = 0;
    };
}
