#pragma once
#include "YageIncludes.h"
#include "GameWindowCreationDesc.h"

BEGIN_YAGE_NAMESPACE


class Game;

class GameWindow
{
public:
	GameWindow( const GameWindowCreationDesc & desc );
	~GameWindow();

	GLFWwindow * _GetWindow() const
	{
		return mWindow;
	}

	int GetWidth() const;
	int GetHeight() const;
	float GetAspectRatio() const;

private:
	void CreateWindowedWindow( const GameWindowCreationDesc & desc );
	void CreateFullScreenWindow( const GameWindowCreationDesc & desc );
	void CreateWindowedFullScreenWindow( const GameWindowCreationDesc & desc );

	GLFWwindow * mWindow;
};


END_YAGE_NAMESPACE