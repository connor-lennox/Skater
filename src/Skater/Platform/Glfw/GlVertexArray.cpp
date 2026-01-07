//
// Created by connor on 12/30/25.
//

#include "GlVertexArray.h"

#include "glad/glad.h"

namespace Skater {
    namespace {
        // TODO: Make these all dynamically set from the VBO layout
        constexpr uint32_t POS_SIZE = 2;
        constexpr uint32_t COLOR_SIZE = 4;
        constexpr uint32_t TEX_COORDS_SIZE = 2;

        constexpr uint32_t POS_OFFSET = 0;
        constexpr uint32_t COLOR_OFFSET = POS_OFFSET + POS_SIZE * sizeof(float);
        constexpr uint32_t TEX_COORDS_OFFSET = COLOR_OFFSET + COLOR_SIZE * sizeof(uint32_t);

        constexpr uint32_t VERTEX_SIZE = POS_SIZE + COLOR_SIZE + TEX_COORDS_SIZE;
        constexpr uint32_t VERTEX_SIZE_BYTES = VERTEX_SIZE * sizeof(float);
    }

    GlVertexArray::GlVertexArray() {
        glCreateVertexArrays(1, &_vaoId);
    }

    GlVertexArray::~GlVertexArray() {
        glDeleteVertexArrays(1, &_vaoId);
    }

    void GlVertexArray::Bind() const {
        glBindVertexArray(_vaoId);
    }

    void GlVertexArray::Unbind() const {
        glBindVertexArray(0);
    }

    void GlVertexArray::SetVertexBuffer(VertexBuffer *buffer) {
        _vertexBuffer = buffer;
        glVertexArrayVertexBuffer(_vaoId, 0, buffer->GetId(), 0, VERTEX_SIZE_BYTES);

        glVertexArrayAttribFormat(_vaoId, 0, POS_SIZE, GL_FLOAT, GL_FALSE, POS_OFFSET);
        glEnableVertexArrayAttrib(_vaoId, 0);
        glVertexArrayAttribBinding(_vaoId, 0, 0);

        glVertexArrayAttribFormat(_vaoId, 1, COLOR_SIZE, GL_FLOAT, GL_FALSE, COLOR_OFFSET);
        glEnableVertexArrayAttrib(_vaoId, 1);
        glVertexArrayAttribBinding(_vaoId, 1, 0);

        glVertexArrayAttribFormat(_vaoId, 2, TEX_COORDS_SIZE, GL_FLOAT, GL_FALSE, TEX_COORDS_OFFSET);
        glEnableVertexArrayAttrib(_vaoId, 2);
        glVertexArrayAttribBinding(_vaoId, 2, 0);
    }

    void GlVertexArray::SetIndexBuffer(IndexBuffer *buffer) {
        glVertexArrayElementBuffer(_vaoId, buffer->GetId());
        _indexBuffer = buffer;
    }
}
