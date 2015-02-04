#pragma once

#include "YageIncludes.h"
#include "ShaderType.h"


class Shader
{
public:
	Shader( ShaderType type );
	~Shader();

private:
	GLuint mId;
	ShaderType mType;
};