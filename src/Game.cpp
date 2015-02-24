#include "Game.h"

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

	this->Load();

	while( glfwWindowShouldClose( mWindow->mWindow ) == false )
	{
		this->Update();
		this->Draw();

		glfwSwapBuffers( mWindow->mWindow );
		glfwPollEvents();
	}

	this->Unload();
}


END_YAGE_NAMESPACE