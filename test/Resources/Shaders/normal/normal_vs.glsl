#version 450

layout (location = 0) in vec3 iPosition;
layout (location = 1) in vec3 iNormal;
layout (location = 2) in vec2 iTexCoord;

uniform mat4 gMVP;

out vec3 normal;

void main() {
    gl_Position = gMVP * vec4(iPosition, 1.0);
    normal = iNormal;
}
