#include "Shader.h"

BEGIN_YAGE_NAMESPACE


Shader::Shader( ShaderType type )
	: mType( type )
	, mIsCompileSucceeded( false )
	, mCompileError( "" )
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
	std::ifstream file( filename );
	std::string str = "";
	str.assign( std::istreambuf_iterator<char>( file ), std::istreambuf_iterator<char>() );

	this->LoadFromString( str );
}


void Shader::LoadFromString( const std::string & str )
{
	const char * cstr = str.c_str();
	glShaderSource( mId, 1, &cstr, NULL );
}


void Shader::Compile()
{
	glCompileShader( mId );

	GLint result = 0;
	glGetShaderiv( mId, GL_COMPILE_STATUS, &result );
	mIsCompileSucceeded = result != GL_FALSE;

	if( mIsCompileSucceeded == false )
	{
		GLint len = 0;
		glGetShaderiv( mId, GL_INFO_LOG_LENGTH, &len );
		if( len > 0 )
		{
			char * buffer = new char[len];
			GLsizei size = 0;
			glGetShaderInfoLog( mIsCompileSucceeded, len, &size, buffer );
			mCompileError = buffer;
			delete[] buffer;
		}
	}
}


END_YAGE_NAMESPACE