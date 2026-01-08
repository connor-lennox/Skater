//
// Created by connor on 1/7/26.
//

#pragma once
#include <cstdint>

namespace Skater {
    enum class JoystickAxis : uint8_t {
        None = 0,

        LeftStickRight = 1,
        LeftStickLeft = 2,
        LeftStickUp = 3,
        LeftStickDown = 4,

        RightStickRight = 5,
        RightStickLeft = 6,
        RightStickUp = 7,
        RightStickDown = 8,

        LeftTrigger = 9,
        RightTrigger = 10
    };
}
