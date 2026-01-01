//
// Created by connor on 12/31/25.
//

#include "Skater/Core/EntityList.h"

#include "Skater/Core/Entity.h"

namespace Skater {
    EntityList::~EntityList() {
        // Free up all our memory
        for (const auto entity : _entities) {
            delete entity;
        }
        _entities.clear();

        for (const auto entity : _toAdd) {
            delete entity;
        }
        _toAdd.clear();

        for (const auto entity : _toRemove) {
            delete entity;
        }
        _toRemove.clear();
    }

    void EntityList::Add(Entity *entity) {
        _toAdd.insert(entity);
    }

    void EntityList::Remove(Entity *entity) {
        _toRemove.insert(entity);
    }

    void EntityList::Clear() {
        for (auto entity : _entities) {
            _toRemove.insert(entity);
        }
    }

    void EntityList::UpdateLists() {
        for (auto entity : _toRemove) {
            std::erase(_entities, entity);
        }

        for (auto entity : _toAdd) {
            _entities.push_back(entity);
        }

        _toAdd.clear();
        _toRemove.clear();
    }

    void EntityList::UpdateEntities() const {
        for (const auto entity : _entities) {
            if (ShouldEntityUpdate(entity)) {
                entity->Update();
            }
        }
    }

    void EntityList::RenderEntities() const {
        for (const auto entity : _entities) {
            if (entity->Visible) {
                entity->Render();
            }
        }
    }

    bool EntityList::ShouldEntityUpdate(const Entity *entity) const {
        // TODO: Consider PauseMode of Entities
        return entity->Active && !ScenePaused;
    }
}
