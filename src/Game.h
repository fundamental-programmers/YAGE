#pragma once
#include "YageIncludes.h"
#include "GameWindow.h"
#include "GraphicsDevice.h"

BEGIN_YAGE_NAMESPACE


class Game
{
public:
	Game();
	~Game();

	void Run();

	GameWindow * GetWindow() const
	{
		return mWindow;
	}

	GraphicsDevice * GetGraphicsDevice() const
	{
		return mGraphicsDevice;
	}

protected:
	virtual void Initialize( GameWindowCreationDesc & desc ) = 0;
	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

private:
	GameWindow * mWindow;
	GraphicsDevice * mGraphicsDevice;
};


END_YAGE_NAMESPACE