//
// Created by connor on 12/31/25.
//

#pragma once
#include <cstdint>
#include <string>

#include "Component.h"
#include "ComponentList.h"
#include "Skater/Math/Vector2.h"

using std::string;

namespace Skater {
    class Entity final {
    public:
        Entity();
        ~Entity();

        void Update();
        void Render() const;

        void AddComponent(Component* component);
        void RemoveComponent(Component* component);
        [[nodiscard]] Component* GetComponent(const string &type) const;

        [[nodiscard]] uint32_t GetId() const { return _id; }

        bool Active = true;
        bool Visible = true;

        Vector2 Position;
    private:
        uint32_t _id;

        ComponentList _components;
    };
}
