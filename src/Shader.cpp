#include "Shader.h"


Shader::Shader( ShaderType type )
: mType( type )
{
	GLenum glShaderType = 0;
	switch( type )
	{
		case ST_Vertex:
			glShaderType = GL_VERTEX_SHADER;
			break;
		case ST_Fragment:
			glShaderType = GL_FRAGMENT_SHADER;
			break;
	}

	mId = glCreateShader( glShaderType );
}


Shader::~Shader()
{
	glDeleteShader( mId );
}