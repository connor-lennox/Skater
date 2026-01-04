//
// Created by connor on 1/3/26.
//

#pragma once
#include "Skater/Renderer/Shader.h"

namespace Skater {
    class GlShader : public Shader {
    public:
        GlShader(const uint8_t *vertexSrc, const uint8_t *fragmentSrc);
        ~GlShader() override;

        void Bind() const override;
        void Unbind() const override;

        void SetInt(const std::string &name, int value) override;
        void SetIntArray(const std::string &name, int* values, uint32_t count) override;
        void SetFloat(const std::string &name, float value) override;
        void SetFloat2(const std::string &name, const Vector2 &value) override;
    private:
        uint32_t _shaderId;
    };
}
