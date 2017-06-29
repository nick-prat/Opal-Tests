#version 450

in vec2 texCoord;
in vec3 lightColor;

out vec4 FragColor;

uniform sampler2D gSampler;
uniform vec4 gAmbientLight;

void main() {
    vec3 ambientColor = gAmbientLight.xyz * gAmbientLight.w;

    FragColor = texture2D(gSampler, texCoord) * vec4(ambientColor + lightColor, 1.0);
}
