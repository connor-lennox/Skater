//
// Created by connor on 12/17/25.
//

#pragma once

#include "KeyboardState.h"

namespace Skater {
    class Keyboard {
    public:
        static KeyboardState GetState();

        static void SetKey(Keys key);
        static void ClearKey(Keys key);
    private:
        static inline KeyboardState _currentState;
    };
}
