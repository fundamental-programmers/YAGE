#pragma once
#include <assimp/vector3.h>
#include "YageIncludes.h"

BEGIN_YAGE_NAMESPACE


class Utilities
{
public:
	static vec3 ToVector3( const aiVector3D & v )
	{
		return vec3( v.x, v.y, v.z );
	}
};


END_YAGE_NAMESPACE