//
// Created by connor on 1/7/26.
//

#pragma once
#include <cstdint>

namespace Skater {
    enum class JoystickButton : uint8_t {
        None = 0,
        A = 1,
        B = 2,
        X = 3,
        Y = 4,
        LeftBumper = 5,
        RightBumper = 6,
        Back = 7,
        Start = 8,
        Guide = 9,
        LeftStick = 10,
        RightStick = 11,
        DPadUp = 12,
        DPadDown = 13,
        DPadLeft = 14,
        DPadRight = 15
    };
}
