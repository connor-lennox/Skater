//
// Created by connor on 12/31/25.
//

#pragma once
#include "RendererAPI.h"

namespace Skater {
    class RenderCommand {
    public:
        static void Init() { _rendererAPI->Init(); }

        static void SetClearColor(const Color color) { _rendererAPI->SetClearColor(color); }
        static void Clear() { _rendererAPI->Clear(); }

        static void DrawIndexed(VertexArray* vertexArray, const uint32_t indexCount) { _rendererAPI->DrawIndexed(vertexArray, indexCount); }
    private:
        static RendererAPI* _rendererAPI;
    };

    inline RendererAPI* RenderCommand::_rendererAPI = RendererAPI::Create();
}
