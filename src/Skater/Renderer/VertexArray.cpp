//
// Created by connor on 12/30/25.
//

#include "Skater/Renderer/VertexArray.h"

#include "../Platform/Glfw/GlVertexArray.h"

namespace Skater {
    VertexArray *VertexArray::Create() {
        return new GlVertexArray();
    }
}
