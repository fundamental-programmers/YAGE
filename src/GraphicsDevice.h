#pragma once
#include "YageIncludes.h"
#include "Color.h"
#include "BufferClearMask.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "DrawMode.h"
#include "ShaderProgram.h"

BEGIN_YAGE_NAMESPACE


class GraphicsDevice
{
public:
	GraphicsDevice();
	~GraphicsDevice();

	Color GetClearColor() const;
	void SetClearColor( const Color & color );

	double GetClearDepth() const;
	void SetClearDepth( double depth );

	int GetClearStencil() const;
	void SetClearStencil( int stencil );

	void Clear( BufferClearMask mask );

	void DrawArrays( VertexBuffer * buffer, DrawMode mode, GLint first, GLsizei count );
	void DrawElements( VertexBuffer * vertexBuffer, IndexBuffer * indexBuffer, DrawMode mode, GLsizei count, const GLvoid * indices );

private:
	void PrepareVertexBuffer( VertexBuffer * buffer );
	void UnprepareVertexBuffer( VertexBuffer * buffer );
};


END_YAGE_NAMESPACE