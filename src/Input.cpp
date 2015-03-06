#include "Input.h"
#include "GameWindow.h"

BEGIN_YAGE_NAMESPACE


GameWindow * Input::sWindow = NULL;


void Input::Initialize( GameWindow * window )
{
	sWindow = window;
	glfwSetKeyCallback( sWindow->_GetWindow(), &Input::OnKey );
}


bool Input::IsKeyDown( KeyCode keyCode )
{
	int state = glfwGetKey( sWindow->_GetWindow(), keyCode );
	return state == GLFW_PRESS;
}


vec2 Input::GetMousePosition()
{
	double x = 0.0, y = 0.0;
	glfwGetCursorPos( sWindow->_GetWindow(), &x, &y );
	return vec2( static_cast<float>( x ), static_cast<float>( y ) );
}


bool Input::IsMouseButtonDown( int button )
{
	int state = glfwGetMouseButton( sWindow->_GetWindow(), button );
	return state == GLFW_PRESS;
}


void Input::OnKey( GLFWwindow * window, int key, int scancode, int action, int mods )
{
}


END_YAGE_NAMESPACE