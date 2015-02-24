#include "FitbosGame.h"


void FitbosGame::Initialize( GameWindowCreationDesc & desc )
{

}

void FitbosGame::Load()
{
	this->GetGraphicsDevice()->SetClearColor( Color::Green );
}

void FitbosGame::Unload()
{

}

void FitbosGame::Update()
{

}

void FitbosGame::Draw()
{
	this->GetGraphicsDevice()->Clear( BCM_Color );
}
