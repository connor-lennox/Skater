//
// Created by connor on 12/30/25.
//

#pragma once
#include "Skater/Renderer/VertexArray.h"

namespace Skater {
    class GlVertexArray final : public VertexArray {
    public:
        GlVertexArray();
        ~GlVertexArray() override;

        void Bind() const override;
        void Unbind() const override;

        void SetVertexBuffer(VertexBuffer* buffer) override;
        void SetIndexBuffer(IndexBuffer* buffer) override;

        [[nodiscard]] VertexBuffer* GetVertexBuffer() const override { return _vertexBuffer; }
        [[nodiscard]] IndexBuffer* GetIndexBuffer() const override { return _indexBuffer; }
    private:
        uint32_t _vaoId = 0;
        VertexBuffer* _vertexBuffer = nullptr;
        IndexBuffer* _indexBuffer = nullptr;
    };
}
