#version 330

struct DirectionalLight
{
    vec4 Color;
    float AmbientIntensity;
};

in vec2 TexCoord0;
in vec3 Normal0;

out vec4 FragColor;

uniform sampler2D DiffuseSampler;

void main()
{
    FragColor = texture2D( DiffuseSampler, TexCoord0 );
}