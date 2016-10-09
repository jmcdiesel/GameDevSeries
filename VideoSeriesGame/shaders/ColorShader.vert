#version 330

in vec4 vertexPosition;
in vec4 vertexColor;

out vec4 fragmentColor;

uniform vec2 translate;

void main() {
    gl_Position.xy = vertexPosition.yx + translate;
    gl_Position.zw = vertexPosition.zw;
    fragmentColor = vertexColor;
}