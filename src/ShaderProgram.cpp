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


bool ShaderProgram::Link()
{
	glLinkProgram( mId );

	GLint status;
	glGetProgramiv( mId, GL_LINK_STATUS, &status );

	if( status == GL_FALSE )
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

	return status != GL_FALSE;
}


void ShaderProgram::Use()
{
	glUseProgram( mId );
}


GLint ShaderProgram::GetUniformLocation( const std::string & name ) const
{
	return glGetUniformLocation( mId, name.c_str() );
}


void ShaderProgram::SetUniform( GLint location, float value )
{
	glUniform1f( location, value );
}


void ShaderProgram::SetUniform( const std::string & name, float value )
{
	GLint location = this->GetUniformLocation( name );
	this->SetUniform( location, value );
}


END_YAGE_NAMESPACE