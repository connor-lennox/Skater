//
// Created by connor on 12/30/25.
//

#include "GlRendererAPI.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Skater {
    GlRendererAPI::~GlRendererAPI() = default;

    void GlRendererAPI::Init() {
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return;
        }

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

    void GlRendererAPI::SetRenderViewportSize(const uint32_t width, const uint32_t height) {
        glViewport(0, 0, width, height);
    }
}
