#pragma once
#include "YageIncludes.h"
#include "VertexAttributeType.h"

BEGIN_YAGE_NAMESPACE


class VertexBuffer;


struct VertexAttribute
{
	VertexAttribute();
	VertexAttribute( GLuint index, GLint size, VertexAttributeType type, GLboolean normalized, GLsizei stride, const GLvoid * pointer );

	void SetToBuffer( VertexBuffer * buffer ) const;

	GLuint Index;
	GLint Size;
	VertexAttributeType Type;
	GLboolean Normalized;
	GLsizei Stride;
	const GLvoid * Pointer;
};


END_YAGE_NAMESPACE