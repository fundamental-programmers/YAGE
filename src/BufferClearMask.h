#pragma once
#include "YageIncludes.h"

BEGIN_YAGE_NAMESPACE


enum BufferClearMask
{
	BCM_Color = GL_COLOR_BUFFER_BIT,
	BCM_Depth = GL_DEPTH_BUFFER_BIT,
	BCM_Stencil = GL_STENCIL_BUFFER_BIT
};


END_YAGE_NAMESPACE