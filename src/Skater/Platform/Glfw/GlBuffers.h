//
// Created by connor on 12/18/25.
//

#pragma once
#include <cstdint>

#include "Skater/Renderer/Buffers.h"

namespace Skater {
    class GlVertexBuffer final : public VertexBuffer {
    public:
        GlVertexBuffer();
        GlVertexBuffer(const float* vertices, uint32_t size);
        ~GlVertexBuffer() override;

        void SetData(const void *data, uint32_t size) const override;

        void Bind() const override;
        void Unbind() const override;
    private:
        uint32_t _rendererId = 0;
    };

    class GlIndexBuffer final : public IndexBuffer {
    public:
        GlIndexBuffer();
        GlIndexBuffer(const uint32_t* vertices, uint32_t count);
        ~GlIndexBuffer() override;

        void SetData(const void *data, uint32_t count) override;

        void Bind() const override;
        void Unbind() const override;

        [[nodiscard]] uint32_t GetCount() const override { return _count; }
    private:
        uint32_t _rendererId = 0;
        uint32_t _count;
    };
}
