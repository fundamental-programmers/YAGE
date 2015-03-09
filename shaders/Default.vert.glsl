#version 330

layout( location = 0 ) in vec3 Position;
layout( location = 1 ) in vec3 TexCoord;
layout( location = 2 ) in vec3 Normal;
layout( location = 3 ) in vec4 Color;
layout( location = 4 ) in vec3 Tangent;
layout( location = 5 ) in vec3 Bitangent;

out vec2 TexCoord0;
out vec3 Normal0;

uniform mat4 matWorld;
uniform mat4 matView;
uniform mat4 matProj;

void main()
{
    gl_Position = matProj * matView * matWorld * vec4( Position, 1.0 );
    TexCoord0 = TexCoord.xy;
    Normal0 = Normal;
}