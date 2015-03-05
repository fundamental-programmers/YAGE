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


void Input::OnKey( GLFWwindow * window, int key, int scancode, int action, int mods )
{
}


END_YAGE_NAMESPACE