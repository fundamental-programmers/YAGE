#include <iostream>
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
	mCamera = new Camera();
	mCamera->SetPerspective( pi<float>() / 2.0f, this->GetWindow()->GetAspectRatio(), 0.1f, 100.0f );
	mCamera->SetPosition( vec3( 0.0f, 0.0f, 3.0f ) );
	mCamera->SetTarget( vec3() );
	mCamera->SetUp( vec3( 0.0f, 1.0f, 0.0f ) );

	mOldMousePosition = Input::GetMousePosition();
	mIsRotatingCamera = false;

	this->GetGraphicsDevice()->SetClearColor( Color::Black );

	float vertices[] =
	{
		-1.0f, -1.0f, 0.5773f, 0.0f, 0.0f,
		0.0f, -1.0f, -1.15475f, 0.5f, 0.0f,
		1.0f, -1.0f, 0.5773f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.5f, 1.0f
	};

	mVertexBuffer = new VertexBuffer();
	mVertexBuffer->SetData( sizeof( vertices ), &vertices, BU_StaticDraw );
	mVertexBuffer->AddAttribute( VertexAttribute( 0, 3, VAT_Float, false, sizeof( float ) * 5, 0 ) );
	mVertexBuffer->AddAttribute( VertexAttribute( 1, 2, VAT_Float, false, sizeof( float ) * 5, reinterpret_cast<const GLvoid *>( sizeof( float ) * 3 ) ) );

	unsigned int indices[] = { 0, 3, 1, 1, 3, 2, 2, 3, 0, 0, 1, 2 };

	mIndexBuffer = new IndexBuffer();
	mIndexBuffer->SetData( sizeof( indices ), &indices, BU_StaticDraw );
	mIndexBuffer->SetIndexType( IT_UnsignedInt );

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

	mTexture = Texture::Load( "textures/test.png" );
	mProgram->SetUniform( mProgram->GetUniformLocation( "Sampler" ), mTexture, 0 );
}


void FitbosGame::Unload()
{
	SafeDelete( mProgram );
	SafeDelete( mFragmentShader );
	SafeDelete( mVertexShader );
	SafeDelete( mVertexBuffer );
	SafeDelete( mCamera );
}


void FitbosGame::Update()
{
	this->UpdateCameraTranslation();
	this->UpdateCameraRotation();

	GLint location = mProgram->GetUniformLocation( "matWorld" );
	mProgram->SetUniform( location, mat4x4() );

	location = mProgram->GetUniformLocation( "matView" );
	mProgram->SetUniform( location, mCamera->GetViewTransform() );

	location = mProgram->GetUniformLocation( "matProj" );
	mProgram->SetUniform( location, mCamera->GetProjectionTransform() );
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

	graphics->DrawElements( mVertexBuffer, mIndexBuffer, DM_Triangles, 12, 0 );
}
