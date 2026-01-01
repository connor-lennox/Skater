//
// Created by connor on 12/31/25.
//

#include "Skater/Core/Component.h"

#include <utility>

namespace Skater {
    namespace {
        uint32_t NextId = 0;
    }

    Component::Component(string type) : _type(std::move(type)) {
        _id = NextId;
        NextId++;
    }
}
