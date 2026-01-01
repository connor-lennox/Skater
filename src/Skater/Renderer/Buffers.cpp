//
// Created by connor on 12/19/25.
//

#include "Skater/Renderer/Buffers.h"

#include <cstdint>

#include "../Platform/Glfw/GlBuffers.h"

namespace Skater {
    VertexBuffer *VertexBuffer::Create() {
        return new GlVertexBuffer();
    }

    VertexBuffer *VertexBuffer::Create(const float *vertices, const uint32_t size) {
        return new GlVertexBuffer(vertices, size);
    }

    IndexBuffer *IndexBuffer::Create() {
        return new GlIndexBuffer();
    }

    IndexBuffer *IndexBuffer::Create(const uint32_t *vertices, const uint32_t size) {
        return new GlIndexBuffer(vertices, size);
    }
}
