//
// Created by connor on 1/4/26.
//

#pragma once
#include "Skater/Color.h"
#include "Skater/Core/Component.h"

namespace Skater {
    class GraphicsComponent : public Component {
    public:
        explicit GraphicsComponent(const string &type)
            : Component(type) {
        }

        Vector2 Offset = Vector2::Zero;
        uint32_t SortingLayer = 0;
        Color ModulateColor = Color::White;
    };
}
