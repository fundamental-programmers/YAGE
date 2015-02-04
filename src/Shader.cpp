#include <iostream>
#include "Shader.h"

BEGIN_YAGE_NAMESPACE


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


void Shader::LoadFromFile( const std::string & filename )
{
	std::ifstream file( filename.c_str() );
	std::string str = "";
	str.assign( std::istreambuf_iterator<char>( file ), std::istreambuf_iterator<char>() );

	std::cout << str << std::endl;

	this->LoadFromString( str );
}


void Shader::LoadFromString( const std::string & str )
{
	const char * cstr = str.c_str();
	glShaderSource( mId, 1, &cstr, NULL );
}


bool Shader::Compile()
{
	glCompileShader( mId );

	GLint result = 0;
	glGetShaderiv( mId, GL_COMPILE_STATUS, &result );

	if( result == GL_FALSE )
	{
		GLint len = 0;
		glGetShaderiv( mId, GL_INFO_LOG_LENGTH, &len );
		if( len > 0 )
		{
			char * buffer = new char[len];
			GLsizei size = 0;
			glGetShaderInfoLog( mId, len, &size, buffer );
			mCompileError = buffer;
			delete[] buffer;
		}
	}

	return result != GL_FALSE;
}


END_YAGE_NAMESPACE