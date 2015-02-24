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
}

void FitbosGame::Unload()
{

}

void FitbosGame::Update()
{
	std::cout << Time::GetMainDeltaTime() << std::endl;
}

void FitbosGame::Draw()
{
	this->GetGraphicsDevice()->Clear( BCM_Color );
}
