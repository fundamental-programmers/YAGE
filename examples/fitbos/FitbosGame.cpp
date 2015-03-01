#include <iostream>
#include "FitbosGame.h"
#include "Time.h"

using namespace Yage;


void FitbosGame::Initialize( GameWindowCreationDesc & desc )
{
}


void FitbosGame::Load()
{
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
}


void FitbosGame::Update()
{
	mat4x4 rotation = rotate( pi<float>() * Time::GetMainTotalTime(), vec3( 0.0f, 1.0f, 0.0f ) );
	GLint location = mProgram->GetUniformLocation( "gRotation" );
	mProgram->SetUniform( location, rotation );
}


void FitbosGame::Draw()
{
	GraphicsDevice * graphics = this->GetGraphicsDevice();
	graphics->Clear( BCM_Color );

	graphics->DrawElements( mVertexBuffer, mIndexBuffer, DM_Triangles, 12, 0 );
}
