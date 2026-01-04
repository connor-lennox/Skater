#version 420 core

layout(location = 0) in vec2 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_Uv;

out vec2 TexCoords;

void main()
{
    gl_Position = vec4(a_Position, 1.0, 1.0);
    TexCoords = a_Uv;
}