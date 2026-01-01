//
// Created by connor on 12/30/25.
//

#pragma once
#include "RenderBatcher.h"
#include "Texture.h"
#include "Skater/Math/Rectangle.h"
#include "Skater/Math/Vector2.h"

namespace Skater {
    class Renderer {
    public:
        Renderer();
        ~Renderer();

        void Start();
        void Finish();

        void Draw(Texture* texture, Vector2 position, Rectangle srcRect, Color color, uint32_t layerDepth);
    private:
        RenderBatcher _batcher;
    };
}
