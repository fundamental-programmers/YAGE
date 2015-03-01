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


void ShaderProgram::SetUniform( GLint location, const vec2 & value )
{
	glUniform2fv( location, value.length(), value_ptr( value ) );
}


void ShaderProgram::SetUniform( GLint location, const vec3 & value )
{
	glUniform3fv( location, 1, value_ptr( value ) );
}


void ShaderProgram::SetUniform( GLint location, const vec4 & value )
{
	glUniform4fv( location, 1, value_ptr( value ) );
}


void ShaderProgram::SetUniform( GLint location, const Color & value )
{
	glUniform2fv( location, 1, reinterpret_cast<const GLfloat *>( &value ) );
}


void ShaderProgram::SetUniform( GLint location, int value )
{
	glUniform1i( location, value );
}


void ShaderProgram::SetUniform( GLint location, unsigned int value )
{
	glUniform1ui( location, value );
}


void ShaderProgram::SetUniform( GLint location, const mat4x4 & value )
{
	glUniformMatrix4fv( location, 1, false, value_ptr( value ) );
}


END_YAGE_NAMESPACE