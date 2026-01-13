//
// Created by connor on 1/3/26.
//

#pragma once
#include <cstdint>
#include <string>

#include "Skater/Math/Matrix4.h"
#include "Skater/Math/Vector2.h"
#include "Skater/Math/Vector3.h"
#include "Skater/Math/Vector4.h"

namespace Skater {
    class Shader {
    public:
        virtual ~Shader() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void SetInt(const std::string &name, int value) = 0;
        virtual void SetIntArray(const std::string &name, int* values, uint32_t count) = 0;
        virtual void SetFloat(const std::string &name, float value) = 0;
        virtual void SetFloat2(const std::string &name, const Vector2 &value) = 0;
        virtual void SetFloat3(const std::string &name, const Vector3 &value) = 0;
        virtual void SetFloat4(const std::string &name, const Vector4 &value) = 0;
        virtual void SetMatrix4(const std::string &name, const Matrix4 &value) = 0;

        static Shader* Create(const uint8_t *vertexSrc, const uint8_t *fragmentSrc);
        static Shader* CreateDefault();
    };
}
