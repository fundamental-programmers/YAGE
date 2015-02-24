#include "GameWindow.h"

BEGIN_YAGE_NAMESPACE


GameWindow::GameWindow( const GameWindowCreationDesc & desc )
{
	switch( desc.FullScreenMode )
	{
		case GWFSM_Windowed:
			this->CreateWindowedWindow( desc );
			break;
		case GWFSM_FullScreen:
			this->CreateFullScreenWindow( desc );
			break;
		case GWFSM_WindowedFullScreen:
			this->CreateWindowedFullScreenWindow( desc );
			break;
	}

	glfwMakeContextCurrent( mWindow );
}


GameWindow::~GameWindow()
{
	glfwDestroyWindow( mWindow );
}


void GameWindow::CreateWindowedWindow( const GameWindowCreationDesc & desc )
{
	mWindow = glfwCreateWindow( desc.Width, desc.Height, desc.Title.c_str(), NULL, NULL );
}


void GameWindow::CreateFullScreenWindow( const GameWindowCreationDesc & desc )
{
	mWindow = glfwCreateWindow( desc.Width, desc.Height, desc.Title.c_str(), glfwGetPrimaryMonitor(), NULL );
}


void GameWindow::CreateWindowedFullScreenWindow( const GameWindowCreationDesc & desc )
{
	GLFWmonitor * monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode * mode = glfwGetVideoMode( glfwGetPrimaryMonitor() );

	glfwWindowHint( GLFW_RED_BITS, mode->redBits );
	glfwWindowHint( GLFW_GREEN_BITS, mode->greenBits );
	glfwWindowHint( GLFW_BLUE_BITS, mode->blueBits );
	glfwWindowHint( GLFW_REFRESH_RATE, mode->refreshRate );

	mWindow = glfwCreateWindow( mode->width, mode->height, desc.Title.c_str(), monitor, NULL );
}


END_YAGE_NAMESPACE