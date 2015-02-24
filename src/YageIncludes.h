#pragma once

#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <fstream>
#include <streambuf>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#define BEGIN_YAGE_NAMESPACE namespace Yage {
#define END_YAGE_NAMESPACE }


template<typename T>
void SafeDelete( T* & ptr )
{
	if( ptr )
	{
		delete ptr;
		ptr = NULL;
	}
}