#pragma once
#include "YageIncludes.h"

BEGIN_YAGE_NAMESPACE


enum BufferUsage
{
	BU_StreamDraw = GL_STREAM_DRAW,
	BU_StreamRead = GL_STREAM_READ,
	BU_StreamCopy = GL_STREAM_COPY,

	BU_StaticDraw = GL_STATIC_DRAW,
	BU_StaticRead = GL_STATIC_READ,
	BU_StaticCopy = GL_STATIC_COPY,

	BU_DynamicDraw = GL_DYNAMIC_DRAW,
	BU_DynamicRead = GL_DYNAMIC_READ,
	BU_DynamicCopy = GL_DYNAMIC_COPY
};


END_YAGE_NAMESPACE