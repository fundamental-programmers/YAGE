#pragma once
#include "YageIncludes.h"

BEGIN_YAGE_NAMESPACE


enum TextureFilter
{
	TF_Nearest = GL_NEAREST,
	TF_Linear = GL_LINEAR,
	TF_NearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
	TF_LinearMipmapNearest = GL_LINEAR_MIPMAP_NEAREST,
	TF_NearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
	TF_LinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR
};


END_YAGE_NAMESPACE