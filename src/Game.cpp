#include "Game.h"
#include "Time.h"
#include "Input.h"

BEGIN_YAGE_NAMESPACE


Game::Game()
{
	glfwInit();
}


Game::~Game()
{
	SafeDelete( mGraphicsDevice );
	SafeDelete( mWindow );

	glfwTerminate();
}


void Game::Run()
{
	GameWindowCreationDesc desc;
	this->Initialize( desc );

	mWindow = new GameWindow( desc );
	mGraphicsDevice = new GraphicsDevice();

	Input::Initialize( mWindow );

	this->Load();

	while( glfwWindowShouldClose( mWindow->_GetWindow() ) == false )
	{
		Time::GetMain()->Update();

		this->Update();
		this->Draw();

		glfwSwapBuffers( mWindow->_GetWindow() );
		glfwPollEvents();
	}

	this->Unload();
}


END_YAGE_NAMESPACE