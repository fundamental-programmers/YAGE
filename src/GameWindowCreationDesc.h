#pragma once
#include "YageIncludes.h"
#include "GameWindowFullScreenMode.h"

BEGIN_YAGE_NAMESPACE


struct GameWindowCreationDesc
{
	int Width;
	int Height;
	std::string Title;
	GameWindowFullScreenMode FullScreenMode;

	GameWindowCreationDesc()
	: Width( 1024 )
	, Height( 768 )
	, Title( "YAGE Game" )
	, FullScreenMode( GWFSM_Windowed )
	{
	}
};


END_YAGE_NAMESPACE