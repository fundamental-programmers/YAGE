#pragma once
#include "YageIncludes.h"
#include "KeyCode.h"

BEGIN_YAGE_NAMESPACE


class GameWindow;


class Input
{
private:
	Input();

public:
	static void Initialize( GameWindow * window );

	static bool IsKeyDown( KeyCode keyCode );

	static vec2 GetMousePosition();
	static bool IsMouseButtonDown( int button );

private:
	static void OnKey( GLFWwindow * window, int key, int scancode, int action, int mods );

	static GameWindow * sWindow;
};


END_YAGE_NAMESPACE