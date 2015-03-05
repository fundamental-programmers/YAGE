#pragma once
#include <Camera.h>
#include "Game.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ShaderProgram.h"

using namespace Yage;


class FitbosGame : public Game
{
protected:
	virtual void Initialize( GameWindowCreationDesc & desc );
	virtual void Load();
	virtual void Unload();
	virtual void Update();
	virtual void Draw();

private:
	VertexBuffer * mVertexBuffer;
	IndexBuffer * mIndexBuffer;
	ShaderProgram * mProgram;
	Shader * mVertexShader;
	Shader * mFragmentShader;
	Camera * mCamera;
};