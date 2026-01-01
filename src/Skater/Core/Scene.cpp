//
// Created by connor on 12/31/25.
//

#include "Skater/Core/Scene.h"

namespace Skater {
    void Scene::Update() {
        _entityList.UpdateLists();
        _entityList.UpdateEntities();
    }

    void Scene::Render() {
        _entityList.RenderEntities();
    }

    void Scene::AddEntity(Entity *entity) {
        _entityList.Add(entity);
    }

    void Scene::RemoveEntity(Entity *entity) {
        _entityList.Remove(entity);
    }
}
