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
}


void ShaderProgram::Use()
{
	glUseProgram( mId );
}


END_YAGE_NAMESPACE