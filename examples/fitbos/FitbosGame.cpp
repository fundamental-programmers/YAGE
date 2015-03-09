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
	Assimp::Importer importer;
	const aiScene * scene = importer.ReadFile( "models/Kirby/Kirby.obj", aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs );
	for( int i = 0; i < scene->mNumMeshes; ++i )
	{
		mMeshes.push_back( Mesh::Load( scene->mMeshes[i] ) );
	}

	mCamera = new Camera();
	mCamera->SetPerspective( pi<float>() / 2.0f, this->GetWindow()->GetAspectRatio(), 0.1f, 100.0f );
	mCamera->SetPosition( vec3( 0.0f, 0.0f, 3.0f ) );
	mCamera->SetTarget( vec3() );
	mCamera->SetUp( vec3( 0.0f, 1.0f, 0.0f ) );

	mOldMousePosition = Input::GetMousePosition();
	mIsRotatingCamera = false;

	mLightColor = Color::White;
	mAmbientIntensity = 1.0f;

	this->GetGraphicsDevice()->SetClearColor( Color::Black );

	mVertexShader = new Shader( ST_Vertex );
	mVertexShader->LoadFromFile( "shaders/Basic.vert.glsl" );
	bool compileResult = mVertexShader->Compile();
	assert( compileResult );

	mFragmentShader = new Shader( ST_Fragment );
	mFragmentShader->LoadFromFile( "shaders/Basic.frag.glsl" );
	compileResult = mFragmentShader->Compile();
	assert( compileResult );

	mProgram = new ShaderProgram();
	mProgram->AttachShader( mVertexShader );
	mProgram->AttachShader( mFragmentShader );
	bool linkResult = mProgram->Link();
	assert( linkResult );

	mProgram->Use();

	//mTexture = Texture::Load( "textures/test.png" );
	//mProgram->SetUniform( mProgram->GetUniformLocation( "Sampler" ), mTexture, 0 );
}


void FitbosGame::Unload()
{
	SafeDelete( mProgram );
	SafeDelete( mFragmentShader );
	SafeDelete( mVertexShader );
	SafeDelete( mCamera );

	std::for_each( mMeshes.begin(), mMeshes.end(), SafeDelete<Mesh> );
}


void FitbosGame::Update()
{
	this->UpdateCameraTranslation();
	this->UpdateCameraRotation();

	if( Input::IsKeyDown( KC_Up ) )
	{
		mAmbientIntensity += 2.0f * Time::GetMainDeltaTime();
	}
	if( Input::IsKeyDown( KC_Down ) )
	{
		mAmbientIntensity -= 2.0f * Time::GetMainDeltaTime();
	}
	if( Input::IsKeyDown( KC_Enter ) )
	{
		mLightColor.R = (float)rand() / RAND_MAX;
		mLightColor.G = (float)rand() / RAND_MAX;
		mLightColor.B = (float)rand() / RAND_MAX;
	}

	GLint location = mProgram->GetUniformLocation( "matWorld" );
	mProgram->SetUniform( location, mat4x4() );

	location = mProgram->GetUniformLocation( "matView" );
	mProgram->SetUniform( location, mCamera->GetViewTransform() );

	location = mProgram->GetUniformLocation( "matProj" );
	mProgram->SetUniform( location, mCamera->GetProjectionTransform() );

	//location = mProgram->GetUniformLocation( "directionalLight.Color" );
	//mProgram->SetUniform( location, mLightColor );

	//location = mProgram->GetUniformLocation( "directionalLight.AmbientIntensity" );
	//mProgram->SetUniform( location, mAmbientIntensity );
}


void FitbosGame::UpdateCameraTranslation()
{
	vec3 moveDir;
	if( Input::IsKeyDown( KC_W ) )
	{
		moveDir += mCamera->GetForward();
	}
	if( Input::IsKeyDown( KC_S ) )
	{
		moveDir -= mCamera->GetForward();
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
		vec3 offset = normalize( moveDir ) * 1.0f * Time::GetMainDeltaTime();
		mCamera->SetPosition( mCamera->GetPosition() + offset );
		mCamera->SetTarget( mCamera->GetTarget() + offset );
	}
}


void FitbosGame::UpdateCameraRotation()
{
	if( ! Input::IsMouseButtonDown( 0 ) )
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
	vec3 newForward = rotation * mCamera->GetForward();
	vec3 target = mCamera->GetPosition() + newForward;

	mCamera->SetTarget( target );
}


void FitbosGame::Draw()
{
	GraphicsDevice * graphics = this->GetGraphicsDevice();
	graphics->Clear( BCM_Color | BCM_Depth );

	for( int i = 0; i < mMeshes.size(); ++i )
	{
		mMeshes[i]->Draw( graphics );
	}
}
