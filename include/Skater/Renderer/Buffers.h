//
// Created by connor on 12/18/25.
//

#pragma once
#include <cstdint>

namespace Skater {
    class VertexBuffer {
    public:
        virtual ~VertexBuffer() = default;

        virtual void SetData(const void* data, uint32_t size) const = 0;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        static VertexBuffer* Create(const float* vertices, uint32_t size);
        static VertexBuffer* Create();
    };

    class IndexBuffer {
    public:
        virtual ~IndexBuffer() = default;

        virtual void SetData(const void* data, uint32_t count) = 0;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        [[nodiscard]] virtual uint32_t GetCount() const = 0;

        static IndexBuffer* Create(const uint32_t* vertices, uint32_t size);
        static IndexBuffer* Create();
    };
}
