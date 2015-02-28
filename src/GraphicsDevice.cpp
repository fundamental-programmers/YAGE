#include "GraphicsDevice.h"

BEGIN_YAGE_NAMESPACE


GraphicsDevice::GraphicsDevice()
{
	glewInit();
}


GraphicsDevice::~GraphicsDevice()
{
}


Color GraphicsDevice::GetClearColor() const
{
	Color color;
	glGetFloatv( GL_COLOR_CLEAR_VALUE, (GLfloat*)&color );
	return color;
}


void GraphicsDevice::SetClearColor( const Color & color )
{
	glClearColor( color.R, color.G, color.B, color.A );
}


double GraphicsDevice::GetClearDepth() const
{
	double depth = 0.0;
	glGetDoublev( GL_DEPTH_CLEAR_VALUE, &depth );
	return depth;
}


void GraphicsDevice::SetClearDepth( double depth )
{
	glClearDepth( depth );
}


int GraphicsDevice::GetClearStencil() const
{
	int stencil = 0;
	glGetIntegerv( GL_STENCIL_CLEAR_VALUE, &stencil );
	return stencil;
}


void GraphicsDevice::SetClearStencil( int stencil )
{
	glClearStencil( stencil );
}


void GraphicsDevice::Clear( BufferClearMask mask )
{
	glClear( mask );
}


void GraphicsDevice::DrawArrays( VertexBuffer * buffer, DrawMode mode, GLint first, GLsizei count )
{
	for( int i = 0; i < buffer->GetAttributeCount(); i++ )
	{
		const VertexAttribute & attribute = buffer->GetAttribute( i );
		glEnableVertexAttribArray( attribute.Index );
		attribute.SetToBuffer( buffer );
	}

	glDrawArrays( mode, first, count );

	for( int i = 0; i < buffer->GetAttributeCount(); i++ )
	{
		const VertexAttribute & attribute = buffer->GetAttribute( i );
		glDisableVertexAttribArray( attribute.Index );
	}
}


END_YAGE_NAMESPACE