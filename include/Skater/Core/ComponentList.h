//
// Created by connor on 12/31/25.
//

#pragma once
#include <string>
#include <unordered_set>
#include <vector>

using std::string;

namespace Skater {
    class Component;

    class ComponentList {
    public:
        ~ComponentList();

        void Add(Component* component);
        void Remove(Component* component);
        void Clear();

        void UpdateLists();

        void UpdateComponents() const;
        void RenderComponents() const;

        [[nodiscard]] Component* GetComponent(const string &type) const;
    private:
        std::vector<Component*> _components;
        std::pmr::unordered_set<Component*> _toAdd;
        std::pmr::unordered_set<Component*> _toRemove;

        std::vector<Component*> _toInit;
    };
}
