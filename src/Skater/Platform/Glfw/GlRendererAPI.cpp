//
// Created by connor on 12/30/25.
//

#include "GlRendererAPI.h"

#include "glad/glad.h"

namespace Skater {
    GlRendererAPI::~GlRendererAPI() = default;

    void GlRendererAPI::Init() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void GlRendererAPI::SetClearColor(const Color color) {
        glClearColor(color.R, color.G, color.B, color.A);
    }

    void GlRendererAPI::Clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void GlRendererAPI::DrawIndexed(VertexArray *vertexArray, const uint32_t indexCount) {
        vertexArray->Bind();
        const uint32_t count = indexCount ? indexCount : vertexArray->GetIndexBuffer()->GetCount();
        glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
    }
}
