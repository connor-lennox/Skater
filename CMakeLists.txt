cmake_minimum_required(VERSION 4.2)
project(Skater)

set(CMAKE_CXX_STANDARD 20)

include(cmake/EmbedResources.cmake)

SET(RESOURCE_FILES
    "resources/gamecontrollerdb.txt"
    "resources/shaders/default_vertex.glsl"
    "resources/shaders/default_fragment.glsl"
)

add_subdirectory("lib/glad")

add_library(${PROJECT_NAME} STATIC
        src/Skater/Game.cpp
        src/Skater/Platform/Glfw/GlWindow.cpp
        src/Skater/Input/Keyboard.cpp
        src/Skater/Input/Input.cpp
        src/Skater/Platform/Glfw/GlBuffers.cpp
        src/Skater/Renderer/Buffers.cpp
        src/Skater/Renderer/Framebuffer.cpp
        src/Skater/Platform/Glfw/GlFramebuffer.cpp
        src/Skater/Renderer/Texture.cpp
        src/Skater/Platform/Glfw/GlTexture.cpp
        src/Skater/Renderer/VertexArray.cpp
        src/Skater/Platform/Glfw/GlVertexArray.cpp
        src/Skater/Renderer/RenderBatcher.cpp
        src/Skater/Renderer/Renderer.cpp
        src/Skater/Renderer/RendererAPI.cpp
        src/Skater/Platform/Glfw/GlRendererAPI.cpp
        src/Skater/Core/ComponentList.cpp
        src/Skater/Core/Component.cpp
        src/Skater/Core/Entity.cpp
        src/Skater/Components/TextureRegion.cpp
        src/Skater/Components/SpriteRenderer.cpp
        src/Skater/Core/EntityList.cpp
        src/Skater/Core/Scene.cpp
        src/Skater/Stb/StbImage.cpp
        src/Skater/Stb/StbTrueType.cpp
        src/Skater/Resources/ResourceDatabase.cpp
        src/Skater/Platform/Glfw/GlShader.cpp
        src/Skater/Renderer/Shader.cpp
        src/Skater/Input/InputAction.cpp
        src/Skater/Input/InputBinding.cpp
        src/Skater/Input/Mouse.cpp
        src/Skater/Input/Gamepad.cpp
        src/Skater/Text/Font.cpp
        src/Skater/Text/FontSystem.cpp
        src/Skater/Components/TextRenderer.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE lib/stb)

target_link_libraries(${PROJECT_NAME} glad)
target_link_libraries(${PROJECT_NAME} glfw)

embed_resources(TARGET ${PROJECT_NAME} RESOURCES ${RESOURCE_FILES})
