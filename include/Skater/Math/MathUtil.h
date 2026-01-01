//
// Created by connor on 12/30/25.
//

#pragma once
#include <cmath>

namespace Skater {
    class MathUtil {
    public:
        static float Distance(const float a, const float b) {
            return std::abs(a - b);
        }

        static float Lerp(const float a, const float b, const float t) {
            return a + (b - a) * t;
        }

        MathUtil() = delete;
    };
}
