#include <iostream>
#include "FitbosGame.h"
#include "Time.h"
#include "Input.h"

using namespace Yage;


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

	this->GetGraphicsDevice()->SetClearColor( Color::Black );

	vec3 vertices[4];
	vertices[0] = vec3( -1.0f, -1.0f, 0.0f );
	vertices[1] = vec3( 0.0f, -1.0f, 1.0f );
	vertices[2] = vec3( 1.0f, -1.0f, 0.0f );
	vertices[3] = vec3( 0.0f, 1.0f, 0.0f );

	mVertexBuffer = new VertexBuffer();
	mVertexBuffer->SetData( sizeof( vertices ), &vertices, BU_StaticDraw );
	mVertexBuffer->AddAttribute( VertexAttribute( 0, 3, VAT_Float, false, 0, 0 ) );

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

	GLint location = mProgram->GetUniformLocation( "matWorld" );
	mProgram->SetUniform( location, mat4x4() );

	location = mProgram->GetUniformLocation( "matView" );
	mProgram->SetUniform( location, mCamera->GetViewTransform() );

	location = mProgram->GetUniformLocation( "matProj" );
	mProgram->SetUniform( location, mCamera->GetProjectionTransform() );
}


void FitbosGame::Draw()
{
	GraphicsDevice * graphics = this->GetGraphicsDevice();
	graphics->Clear( BCM_Color | BCM_Depth );

	graphics->DrawElements( mVertexBuffer, mIndexBuffer, DM_Triangles, 12, 0 );
}
