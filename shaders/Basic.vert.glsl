#version 330

layout( location = 0 ) in vec3 Position;

out vec4 Color;

uniform mat4 gRotation;

void main()
{
    Color = gRotation * vec4( clamp( Position, 0.0, 1.0 ), 1.0 );
    gl_Position = gRotation * vec4( Position, 1.0 );
}