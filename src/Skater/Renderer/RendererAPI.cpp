//
// Created by connor on 12/30/25.
//

#include "Skater/Renderer/RendererAPI.h"

#include "../Platform/Glfw/GlRendererAPI.h"

namespace Skater {
    RendererAPI *RendererAPI::Create() {
        return new GlRendererAPI();
    }
}
