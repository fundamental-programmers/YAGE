#version 330

layout( location = 0 ) in vec3 Position;
layout( location = 1 ) in vec2 TexCoord;

out vec2 TexCoord0;

uniform mat4 matWorld;
uniform mat4 matView;
uniform mat4 matProj;

void main()
{
    gl_Position = matProj * matView * matWorld * vec4( Position, 1.0 );
    TexCoord0 = TexCoord;
}