//
// Created by connor on 12/30/25.
//

#pragma once
#include "Skater/Renderer/RendererAPI.h"

namespace Skater {
    class GlRendererAPI final : public RendererAPI {
    public:
        ~GlRendererAPI() override;

        void Init() override;

        void SetClearColor(Color color) override;
        void Clear() override;

        void DrawIndexed(VertexArray *vertexArray, uint32_t indexCount) override;

        void SetRenderViewportSize(uint32_t width, uint32_t height) override;
    };
}
