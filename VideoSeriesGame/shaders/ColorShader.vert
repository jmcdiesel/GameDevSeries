#version 330

in vec2 vertexPosition;

uniform vec2 translate;

void main() {
    gl_Position.xy = vertexPosition + translate;
    gl_Position.z = 0;
    gl_Position.w = 1;
}