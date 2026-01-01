//
// Created by connor on 12/30/25.
//

#pragma once
#include "VertexArray.h"
#include "Skater/Color.h"

namespace Skater {
    class RendererAPI {
    public:
        virtual ~RendererAPI() = default;

        virtual void Init() = 0;

        virtual void SetClearColor(Color color) = 0;
        virtual void Clear() = 0;

        virtual void DrawIndexed(VertexArray* vertexArray, uint32_t indexCount) = 0;

        static RendererAPI* Create();
    };
}
