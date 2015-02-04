#pragma once

#include "YageIncludes.h"
#include "Shader.h"

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

private:
	GLuint mId;
	std::string mLinkError;
};


END_YAGE_NAMESPACE