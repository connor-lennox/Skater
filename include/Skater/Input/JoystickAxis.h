//
// Created by connor on 1/7/26.
//

#pragma once
#include <cstdint>

namespace Skater {
    enum class JoystickAxis : uint8_t {
        None = 0,
        LeftX = 1,
        LeftY = 2,
        RightX = 3,
        RightY = 4,
        LeftTrigger = 5,
        RightTrigger = 6
    };
}
