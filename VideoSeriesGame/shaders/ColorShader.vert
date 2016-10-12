#version 330

in vec4 vertexPosition;
in vec4 vertexColor;

uniform vec2 translate;

out vec4 fragmentColor;

void main() {
    gl_Position.xy = vertexPosition.xy + translate;
    gl_Position.z = 0;
    gl_Position.w = 1;
    
    fragmentColor = vertexColor;
}