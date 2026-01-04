#version 420 core

in vec2 TexCoords;
out vec4 color;

layout(binding = 0) uniform sampler2D image;
uniform vec4 spriteColor;

void main() {
    color = texture(image, TexCoords);
    if (color.a < 0.1) {
        discard;
    }
}