//
// Created by connor on 12/31/25.
//

#include "Skater/Core/Entity.h"

namespace Skater {
    namespace {
        uint32_t NextId = 0;
    }

    Entity::Entity() {
        _id = NextId;
        NextId++;
    }

    Entity::~Entity() = default;

    void Entity::Update() {
        _components.UpdateLists();
        _components.UpdateComponents();
    }

    void Entity::Render() const {
        _components.RenderComponents();
    }

    void Entity::AddComponent(Component *component) {
        component->SetEntity(this);
        _components.Add(component);
    }

    void Entity::RemoveComponent(Component *component) {
        component->SetEntity(nullptr);
        _components.Remove(component);
    }

    Component* Entity::GetComponent(const string &type) const {
        return _components.GetComponent(type);
    }
}
