//
// Created by connor on 12/31/25.
//

#pragma once
#include <cstdint>
#include <string>

using std::string;

namespace Skater {
    class Entity;

    class Component {
    public:
        explicit Component(string type);
        virtual ~Component() = default;

        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;

        [[nodiscard]] uint32_t GetId() const { return _id; }
        [[nodiscard]] string GetType() const { return _type; }

        bool Active = true;

        void SetEntity(Entity* entity) { _entity = entity; }
    protected:
        Entity* _entity;
    private:
        uint32_t _id;
        string _type;
    };
}

#include "Entity.h"