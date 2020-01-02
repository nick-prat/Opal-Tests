#version 450

layout (location = 0) in vec3 iPosition;
layout (location = 1) in vec3 iColor;

uniform mat4 gMVP;

out vec4 color;

void main() {
    gl_Position = gMVP * vec4(iPosition, 1.0);
    color = vec4(iColor, 1.0);
}
