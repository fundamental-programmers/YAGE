#include <iostream>
#include <GL/glew.h>
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

	glewInit();

	cout << "GL Vendor: " << glGetString( GL_VENDOR ) << endl;
	cout << "GL Renderer: " << glGetString( GL_RENDERER ) << endl;
	cout << "GL Version: " << glGetString( GL_VERSION ) << endl;
	cout << "GLSL Version: " << glGetString( GL_SHADING_LANGUAGE_VERSION ) << endl;

	while( !glfwWindowShouldClose( window ) )
	{
		glfwSwapBuffers( window );
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}