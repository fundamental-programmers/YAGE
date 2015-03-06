#pragma once

#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <fstream>
#include <streambuf>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>

using namespace glm;


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