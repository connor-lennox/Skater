//
// Created by connor on 12/17/25.
//

#pragma once
#include "KeyboardState.h"
#include "Keys.h"

namespace Skater {
    class Input {
    public:
        static void Update();

        static bool IsKeyPressed(Keys key);
        static bool IsKeyJustPressed(Keys key);
        static bool IsKeyJustReleased(Keys key);
    private:
        static inline KeyboardState _previousState;
        static inline KeyboardState _currentState;
    };
}
