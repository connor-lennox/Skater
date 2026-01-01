//
// Created by connor on 12/31/25.
//

#pragma once
#include <unordered_set>
#include <vector>

namespace Skater {
    class Entity;

    class EntityList {
    public:
        ~EntityList();

        void Add(Entity* entity);
        void Remove(Entity* entity);
        void Clear();

        void UpdateLists();

        void UpdateEntities() const;
        void RenderEntities() const;

        bool ScenePaused = false;
    private:
        std::vector<Entity*> _entities;
        std::pmr::unordered_set<Entity*> _toAdd;
        std::pmr::unordered_set<Entity*> _toRemove;
        bool ShouldEntityUpdate(const Entity* entity) const;
    };
}
