#version 450

layout (points) in;
layout (line_strip, max_vertices = 256) out;

in vec3 normal[];

void main() {
    gl_Position = gl_in[0].gl_Position;
    EmitVertex();
    gl_Position = gl_in[0].gl_Position + normalize(vec4(normal[0], 0.0)) / 5;
    EmitVertex();
}
