#pragma once
#include <Camera.h>
#include "Game.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include "Mesh.h"

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

	std::vector<Mesh*> mMeshes;
	ShaderProgram * mProgram;
	Shader * mVertexShader;
	Shader * mFragmentShader;
	Texture * mTexture;
	Camera * mCamera;
	Color mLightColor;
	float mAmbientIntensity;
	vec2 mOldMousePosition;
	bool mIsRotatingCamera;
};