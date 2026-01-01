//
// Created by connor on 12/31/25.
//

#pragma once
#include "Entity.h"
#include "EntityList.h"

namespace Skater {
    class Scene {
    public:
        bool Paused;

        void Update();
        void Render();

        void AddEntity(Entity* entity);
        void RemoveEntity(Entity* entity);
    private:
        EntityList _entityList;
    };
}
