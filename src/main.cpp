#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

int main()
{
	if( glfwInit() == -1 )
	{
		return -1;
	}

	GLFWwindow * window = glfwCreateWindow( 1024, 768, "TestCLion", NULL, NULL );
	if( window == NULL )
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent( window );

	cout << glGetString( GL_VERSION ) << endl;

	while( !glfwWindowShouldClose( window ) )
	{
		glfwSwapBuffers( window );
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}