#version 330

in vec2 TexCoord0;

out vec4 FragColor;

uniform sampler2D Sampler;

void main()
{
    FragColor = texture2D( Sampler, TexCoord0 );
}