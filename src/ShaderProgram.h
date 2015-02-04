#pragma once

#include "YageIncludes.h"
#include "Shader.h"

BEGIN_YAGE_NAMESPACE


class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();

	bool IsLinkSucceeded() const
	{
		return mIsLinkSucceeded;
	}

	const std::string & GetLinkError() const
	{
		return mLinkError;
	}

	void AttachShader( Shader * shader );
	void DetachShader( Shader * shader );

	void Link();
	void Use();

private:
	GLuint mId;
	std::vector<Shader *> mShaders;
	bool mIsLinkSucceeded;
	std::string mLinkError;
};


END_YAGE_NAMESPACE