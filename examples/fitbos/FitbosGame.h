#pragma once
#include "Game.h"
#include "VertexBuffer.h"

using namespace Yage;


class FitbosGame : public Game
{
protected:
	virtual void Initialize( GameWindowCreationDesc & desc );
	virtual void Load();
	virtual void Unload();
	virtual void Update();
	virtual void Draw();

private:
	VertexBuffer * mVertexBuffer;
};