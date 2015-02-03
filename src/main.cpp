#include <iostream>
#include <GLFW/glfw3.h>
#include <glm.hpp>

using namespace std;

int main()
{
	if( glfwInit() == -1 )
	{
		return -1;
	}

	glm::fvec2 v( 3.0f, 4.0f );
	cout << glm::length( v ) << endl;

	GLFWwindow * window = glfwCreateWindow( 1024, 768, "TestCLion", NULL, NULL );
	if( window == NULL )
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent( window );

	while( !glfwWindowShouldClose( window ) )
	{
		glfwSwapBuffers( window );
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}