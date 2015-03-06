#pragma once
#include <Camera.h>
#include "Game.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ShaderProgram.h"
#include "Texture.h"

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
	static const float CameraRotationSpeed;

	void UpdateCameraTranslation();
	void UpdateCameraRotation();

	VertexBuffer * mVertexBuffer;
	IndexBuffer * mIndexBuffer;
	ShaderProgram * mProgram;
	Shader * mVertexShader;
	Shader * mFragmentShader;
	Texture * mTexture;
	Camera * mCamera;
	vec2 mOldMousePosition;
	bool mIsRotatingCamera;
};