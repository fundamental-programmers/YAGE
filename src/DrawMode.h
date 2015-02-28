#pragma once
#include "YageIncludes.h"

BEGIN_YAGE_NAMESPACE


enum DrawMode
{
	DM_Points = GL_POINTS,
	DM_LineStrip = GL_LINE_STRIP,
	DM_LineLoop = GL_LINE_LOOP,
	DM_Lines = GL_LINES,
	DM_LineStripAdjacency = GL_LINE_STRIP_ADJACENCY,
	DM_LinesAdjacency = GL_LINES_ADJACENCY,
	DM_TriangleStrip = GL_TRIANGLE_STRIP,
	DM_TriangleFan = GL_TRIANGLE_FAN,
	DM_Triangles = GL_TRIANGLES,
	DM_TriangleStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
	DM_TrianglesAdjacency = GL_TRIANGLES_ADJACENCY
};


END_YAGE_NAMESPACE