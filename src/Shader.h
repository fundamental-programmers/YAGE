#pragma once

#include "YageIncludes.h"
#include "ShaderType.h"

BEGIN_YAGE_NAMESPACE


class ShaderProgram;


class Shader
{
public:
	Shader( ShaderType type );
	~Shader();

	friend class ShaderProgram;

	ShaderType GetType() const
	{
		return mType;
	}

	const std::string & GetCompileError() const
	{
		return mCompileError;
	}

	void LoadFromFile( const std::string & filename );
	void LoadFromString( const std::string & str );

	bool Compile();

private:
	GLuint mId;
	ShaderType mType;
	std::string mCompileError;
};


END_YAGE_NAMESPACE