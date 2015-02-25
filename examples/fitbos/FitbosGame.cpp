#include <iostream>
#include "FitbosGame.h"
#include "Time.h"

using namespace Yage;


void FitbosGame::Initialize( GameWindowCreationDesc & desc )
{

}

void FitbosGame::Load()
{
	this->GetGraphicsDevice()->SetClearColor( Color::Green );

	glm::vec3 vertex;

	mVertexBuffer = new VertexBuffer();
	mVertexBuffer->SetData( sizeof( vertex ), &vertex, BU_StaticDraw );
}

void FitbosGame::Unload()
{
	SafeDelete( mVertexBuffer );
}

void FitbosGame::Update()
{
	std::cout << Time::GetMainDeltaTime() << std::endl;
}

void FitbosGame::Draw()
{
	this->GetGraphicsDevice()->Clear( BCM_Color );
}
