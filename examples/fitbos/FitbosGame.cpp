#include <iostream>
#include "FitbosGame.h"
#include "Vector3.h"
#include "Time.h"

using namespace Yage;


void FitbosGame::Initialize( GameWindowCreationDesc & desc )
{
}


void FitbosGame::Load()
{
	this->GetGraphicsDevice()->SetClearColor( Color::Black );

	Vector3 vertices[3];
	vertices[0] = Vector3( -1.0f, -1.0f, 0.0f );
	vertices[1] = Vector3( 1.0f, -1.0f, 0.0f );
	vertices[2] = Vector3( 0.0f, 1.0f, 0.0f );

	mVertexBuffer = new VertexBuffer();
	mVertexBuffer->SetData( sizeof( vertices ), &vertices, BU_StaticDraw );
	mVertexBuffer->AddAttribute( VertexAttribute( 0, 3, VAT_Float, false, 0, 0 ) );

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
}


void FitbosGame::Unload()
{
	SafeDelete( mProgram );
	SafeDelete( mFragmentShader );
	SafeDelete( mVertexShader );
	SafeDelete( mVertexBuffer );
}


void FitbosGame::Update()
{
}


void FitbosGame::Draw()
{
	GraphicsDevice * graphics = this->GetGraphicsDevice();
	graphics->Clear( BCM_Color );

	mProgram->Use();

	graphics->DrawArrays( mVertexBuffer, DM_Triangles, 0, 3 );
}
