#version 450

layout (location = 0) in vec3 iPosition;
layout (location = 1) in vec3 iNormal;
layout (location = 2) in vec2 iTexCoord;

layout (std140) uniform SunLight {
    vec4 gSunColor;
    vec4 gSunDirection;
};

uniform mat4 gMVP;

out vec2 texCoord;
out vec3 lightColor;

void main() {
    float lpow = dot(normalize(gSunDirection.xyz), normalize(iNormal));
    lightColor = clamp(gSunColor.xyz * lpow, 0.0, 1.0);
    gl_Position = gMVP * vec4(iPosition, 1.0);
    texCoord = iTexCoord;
}
