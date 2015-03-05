#version 330

layout( location = 0 ) in vec3 Position;

out vec4 Color;

uniform mat4 matWorld;
uniform mat4 matView;
uniform mat4 matProj;

void main()
{
    Color = vec4( clamp( Position, 0.0, 1.0 ), 1.0 );
    gl_Position = matProj * matView * matWorld * vec4( Position, 1.0 );
}