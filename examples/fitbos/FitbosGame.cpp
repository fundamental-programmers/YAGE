#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include "FitbosGame.h"
#include "Time.h"
#include "Input.h"

using namespace Yage;


const float FitbosGame::CameraRotationSpeed = 0.001f;


void FitbosGame::Initialize( GameWindowCreationDesc & desc )
{
}


void FitbosGame::Load()
{
	mScene = Scene::Load( "models/RinFigure.obj" );

	mCamera = new Camera();
	mCamera->SetFov( pi<float>() / 4.0f );
	mCamera->SetAspectRatio( this->GetWindow()->GetAspectRatio() );
	mCamera->SetPosition( vec3( 0.0f, 0.0f, 3.0f ) );

	mOldMousePosition = Input::GetMousePosition();
	mIsRotatingCamera = false;

	this->GetGraphicsDevice()->SetClearColor( Color::Black );
}


void FitbosGame::Unload()
{
	SafeDelete( mCamera );
	SafeDelete( mScene );
}


void FitbosGame::Update()
{
	this->UpdateCameraTranslation();
	this->UpdateCameraRotation();

	GraphicsDevice * graphics = this->GetGraphicsDevice();
	ShaderProgram * program = graphics->GetDefaultShaderProgram();

	GLint location = program->GetUniformLocation( "matWorld" );
	program->SetUniform( location, mat4x4() );

	location = program->GetUniformLocation( "matView" );
	program->SetUniform( location, mCamera->GetViewTransform() );

	location = program->GetUniformLocation( "matProj" );
	program->SetUniform( location, mCamera->GetProjectionTransform() );
}


void FitbosGame::UpdateCameraTranslation()
{
	vec3 moveDir;
	if( Input::IsKeyDown( KC_W ) )
	{
		moveDir += mCamera->GetDirection();
	}
	if( Input::IsKeyDown( KC_S ) )
	{
		moveDir -= mCamera->GetDirection();
	}
	if( Input::IsKeyDown( KC_A ) )
	{
		moveDir += mCamera->GetLeft();
	}
	if( Input::IsKeyDown( KC_D ) )
	{
		moveDir -= mCamera->GetLeft();
	}
	if( Input::IsKeyDown( KC_E ) )
	{
		moveDir += mCamera->GetUp();
	}
	if( Input::IsKeyDown( KC_Q ) )
	{
		moveDir -= mCamera->GetUp();
	}

	if( moveDir != vec3() )
	{
		vec3 offset = normalize( moveDir ) * 5.0f * Time::GetMainDeltaTime();
		mCamera->SetPosition( mCamera->GetPosition() + offset );
	}
}


void FitbosGame::UpdateCameraRotation()
{
	if( ! Input::IsMouseButtonDown( 1 ) )
	{
		mIsRotatingCamera = false;
		return;
	}

	if( ! mIsRotatingCamera )
	{
		mOldMousePosition = Input::GetMousePosition();
		mIsRotatingCamera = true;
		return;
	}

	vec2 currentMousePosition = Input::GetMousePosition();
	vec2 mouseDelta = currentMousePosition - mOldMousePosition;
	mOldMousePosition = currentMousePosition;

	vec2 yawPitch = mouseDelta * CameraRotationSpeed;

	quat rotation( vec3( -yawPitch.y, -yawPitch.x, 0.0f ) );
	vec3 newForward = rotation * mCamera->GetDirection();

	mCamera->SetDirection( newForward );
}


void FitbosGame::Draw()
{
	GraphicsDevice * graphics = this->GetGraphicsDevice();
	graphics->Clear( BCM_Color | BCM_Depth );

	mScene->Draw( graphics );
}
