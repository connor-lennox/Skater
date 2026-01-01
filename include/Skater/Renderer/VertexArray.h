//
// Created by connor on 12/30/25.
//

#pragma once
#include "Buffers.h"

namespace Skater {
    class VertexArray {
    public:
        virtual ~VertexArray() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void SetVertexBuffer(VertexBuffer* buffer) = 0;
        virtual void SetIndexBuffer(IndexBuffer* buffer) = 0;

        [[nodiscard]] virtual VertexBuffer* GetVertexBuffer() const = 0;
        [[nodiscard]] virtual IndexBuffer* GetIndexBuffer() const = 0;

        static VertexArray* Create();
    };
}
