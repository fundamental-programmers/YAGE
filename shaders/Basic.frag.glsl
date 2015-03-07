#version 330

struct DirectionalLight
{
    vec4 Color;
    float AmbientIntensity;
};

in vec2 TexCoord0;

out vec4 FragColor;

uniform sampler2D Sampler;
uniform DirectionalLight directionalLight;

void main()
{
    FragColor = texture2D( Sampler, TexCoord0 ) * directionalLight.Color * directionalLight.AmbientIntensity;
}