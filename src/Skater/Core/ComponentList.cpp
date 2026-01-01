//
// Created by connor on 12/31/25.
//

#include "Skater/Core/ComponentList.h"

#include "Skater/Core/Component.h"

namespace Skater {
    ComponentList::~ComponentList() {
        // Free up all our memory
        for (const auto component : _components) {
            delete component;
        }
        _components.clear();

        for (const auto component : _toAdd) {
            delete component;
        }
        _toAdd.clear();

        for (const auto component : _toRemove) {
            delete component;
        }
        _toRemove.clear();
    }

    void ComponentList::Add(Component *component) {
        _toAdd.insert(component);
    }

    void ComponentList::Remove(Component *component) {
        _toRemove.insert(component);
    }

    void ComponentList::Clear() {
        for (auto component : _components) {
            _toRemove.insert(component);
        }
    }

    void ComponentList::UpdateLists() {
        for (auto component : _toRemove) {
            std::erase(_components, component);
        }

        for (auto component : _toAdd) {
            _components.push_back(component);
            _toInit.push_back(component);
        }

        _toAdd.clear();
        _toRemove.clear();

        for (const auto component : _toInit) {
            component->Init();
        }
        _toInit.clear();
    }

    void ComponentList::UpdateComponents() const {
        for (const auto component : _components) {
            if (component->Active) {
                component->Update();
            }
        }
    }

    void ComponentList::RenderComponents() const {
        for (const auto component : _components) {
            if (component->Active) {
                component->Render();
            }
        }
    }

    Component* ComponentList::GetComponent(const string &type) const {
        for (const auto component : _components) {
            if (component->GetType() == type) {
                return component;
            }
        }

        return nullptr;
    }
}
