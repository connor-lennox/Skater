//
// Created by connor on 12/30/25.
//

#include "GlVertexArray.h"

#include "glad/glad.h"

namespace Skater {
    namespace {
        // TODO: Make these all dynamically set from the VBO layout
        constexpr uint32_t POS_SIZE = 2;
        constexpr uint32_t COLOR_SIZE = 1;
        constexpr uint32_t TEX_COORDS_SIZE = 2;
        constexpr uint32_t TEX_ID_SIZE = 1;
        constexpr uint32_t ENTITY_ID_SIZE = 1;

        constexpr uint32_t POS_OFFSET = 0;
        constexpr uint32_t COLOR_OFFSET = POS_OFFSET + POS_SIZE * sizeof(float);
        constexpr uint32_t TEX_COORDS_OFFSET = COLOR_OFFSET + COLOR_SIZE * sizeof(uint32_t);
        constexpr uint32_t TEX_ID_OFFSET = TEX_COORDS_OFFSET + TEX_COORDS_SIZE * sizeof(float);
        constexpr uint32_t ENTITY_ID_OFFSET = TEX_ID_OFFSET + TEX_ID_SIZE * sizeof(float);

        constexpr uint32_t VERTEX_SIZE = POS_SIZE + COLOR_SIZE + TEX_COORDS_SIZE + TEX_ID_SIZE + ENTITY_ID_SIZE;
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
        glBindVertexArray(_vaoId);
        buffer->Bind();

        glVertexAttribPointer(0, POS_SIZE, GL_FLOAT, GL_FALSE, VERTEX_SIZE_BYTES, reinterpret_cast<void *>(POS_OFFSET));
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, COLOR_SIZE, GL_FLOAT, GL_FALSE, VERTEX_SIZE_BYTES, reinterpret_cast<void *>(COLOR_OFFSET));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, TEX_COORDS_SIZE, GL_FLOAT, GL_FALSE, VERTEX_SIZE_BYTES, reinterpret_cast<void *>(TEX_COORDS_OFFSET));
        glEnableVertexAttribArray(2);

        glVertexAttribPointer(3, TEX_ID_SIZE, GL_FLOAT, GL_FALSE, VERTEX_SIZE_BYTES, reinterpret_cast<void *>(TEX_ID_OFFSET));
        glEnableVertexAttribArray(3);

        glVertexAttribPointer(4, ENTITY_ID_SIZE, GL_FLOAT, GL_FALSE, VERTEX_SIZE_BYTES, reinterpret_cast<void *>(ENTITY_ID_OFFSET));
        glEnableVertexAttribArray(4);
    }

    void GlVertexArray::SetIndexBuffer(IndexBuffer *buffer) {
        glBindVertexArray(_vaoId);
        buffer->Bind();
        _indexBuffer = buffer;
    }
}
