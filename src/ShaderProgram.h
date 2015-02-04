#pragma once

#include "YageIncludes.h"
#include "Shader.h"

BEGIN_YAGE_NAMESPACE


class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();

	void AttachShader( Shader * shader );
	void DetachShader( Shader * shader );

	void Link();
	void Use();

private:
	GLuint mId;
	std::vector<Shader*> mShaders;
};


END_YAGE_NAMESPACE