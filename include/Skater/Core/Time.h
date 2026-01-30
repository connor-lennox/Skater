//
// Created by connor on 1/29/26.
//

#pragma once
#include <chrono>

namespace Skater {
    class Time {
    public:
        static void Tick();
        static float DeltaTime() { return _deltaTime; }
    private:
        inline static std::chrono::steady_clock::time_point _lastTick = std::chrono::steady_clock::now();

        inline static float _deltaTime;
    };
}
