//
// Created by connor on 12/18/25.
//

#include "GlBuffers.h"

#include "glad/glad.h"

namespace Skater {
    // VertexBuffer
    GlVertexBuffer::GlVertexBuffer() {
        glCreateBuffers(1, &_rendererId);
    }

    GlVertexBuffer::GlVertexBuffer(const float* vertices, const uint32_t size) {
        glCreateBuffers(1, &_rendererId);
        glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    GlVertexBuffer::~GlVertexBuffer() {
        glDeleteBuffers(1, &_rendererId);
    }

    void GlVertexBuffer::SetData(const void *data, const uint32_t size) const {
        glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }

    void GlVertexBuffer::Bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
    }

    void GlVertexBuffer::Unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }


    // IndexBuffer
    GlIndexBuffer::GlIndexBuffer() : _count(0) {
        glCreateBuffers(1, &_rendererId);
    }

    GlIndexBuffer::GlIndexBuffer(const uint32_t *vertices, const uint32_t count) : _count(count) {
        glCreateBuffers(1, &_rendererId);
        glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
        glBufferData(GL_ARRAY_BUFFER, _count * sizeof(uint32_t), vertices, GL_STATIC_DRAW);
    }

    GlIndexBuffer::~GlIndexBuffer() {
        glDeleteBuffers(1, &_rendererId);
    }

    void GlIndexBuffer::SetData(const void *data, const uint32_t count) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererId);
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, count * sizeof(uint32_t), data);
        _count = count;
    }

    void GlIndexBuffer::Bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererId);
    }

    void GlIndexBuffer::Unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}