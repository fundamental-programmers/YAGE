#pragma once

#include "YageIncludes.h"
#include "Shader.h"
#include "Color.h"

BEGIN_YAGE_NAMESPACE


class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();

	const std::string & GetLinkError() const
	{
		return mLinkError;
	}

	void AttachShader( Shader * shader );
	void DetachShader( Shader * shader );

	bool Link();
	void Use();

	GLint GetUniformLocation( const std::string & name ) const;

	void SetUniform( GLint location, float value );
	void SetUniform( GLint location, const vec2 & value );
	void SetUniform( GLint location, const vec3 & value );
	void SetUniform( GLint location, const vec4 & value );
	void SetUniform( GLint location, const Color & value );
	void SetUniform( GLint location, int value );
	void SetUniform( GLint location, unsigned int value );
	void SetUniform( GLint location, const mat4x4 & value );

private:
	GLuint mId;
	std::string mLinkError;
};


END_YAGE_NAMESPACE