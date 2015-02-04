#include "ShaderProgram.h"

BEGIN_YAGE_NAMESPACE


ShaderProgram::ShaderProgram()
{
	mId = glCreateProgram();
}


ShaderProgram::~ShaderProgram()
{
	glDeleteProgram( mId );
}


void ShaderProgram::AttachShader( Shader * shader )
{
	glAttachShader( mId, shader->mId );
}


void ShaderProgram::DetachShader( Shader * shader )
{
	glDetachShader( mId, shader->mId );
}


void ShaderProgram::Link()
{
	glLinkProgram( mId );

	GLint status;
	glGetProgramiv( mId, GL_LINK_STATUS, &status );
	mIsLinkSucceeded = status != GL_FALSE;

	if( mIsLinkSucceeded == false )
	{
		GLint len = 0;
		glGetProgramiv( mId, GL_INFO_LOG_LENGTH, &len );
		if( len > 0 )
		{
			char * buffer = new char[len];
			GLsizei size = 0;
			glGetProgramInfoLog( mId, len, &size, buffer );
			mLinkError = buffer;
			delete[] buffer;
		}
	}
}


void ShaderProgram::Use()
{
	glUseProgram( mId );
}


END_YAGE_NAMESPACE