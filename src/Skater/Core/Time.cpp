//
// Created by connor on 1/29/26.
//

#include "Skater/Core/Time.h"

using namespace std::chrono;

namespace Skater {
    void Time::Tick() {
        const auto t2 = steady_clock::now();
        const auto span = duration_cast<duration<float>>(t2 - _lastTick);
        _deltaTime = span.count();
        _lastTick = t2;
    }
}
