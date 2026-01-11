#version 420 core
layout(location = 0) in vec2 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_Uv;

uniform mat4 uProjection;

out vec4 tintColor;
out vec2 TexCoords;

void main()
{
    gl_Position = uProjection * vec4(a_Position, 0.0, 1.0);
    tintColor = a_Color;
    TexCoords = a_Uv;
}