#include "GraphicsDevice.h"

BEGIN_YAGE_NAMESPACE


GraphicsDevice::GraphicsDevice()
{
	glewInit();

	glFrontFace( GL_CCW );
	glCullFace( GL_BACK );
	glEnable( GL_CULL_FACE );

	glEnable( GL_DEPTH_TEST );

	mDefaultVertexShader = new Shader( ST_Vertex );
	mDefaultVertexShader->LoadFromFile( "shaders/Default.vert.glsl" );
	bool compileResult = mDefaultVertexShader->Compile();
	assert( compileResult );

	mDefaultFragmentShader = new Shader( ST_Fragment );
	mDefaultFragmentShader->LoadFromFile( "shaders/Default.frag.glsl" );
	compileResult = mDefaultFragmentShader->Compile();
	assert( compileResult );

	mDefaultShaderProgram = new ShaderProgram();
	mDefaultShaderProgram->AttachShader( mDefaultVertexShader );
	mDefaultShaderProgram->AttachShader( mDefaultFragmentShader );
	bool linkResult = mDefaultShaderProgram->Link();
	assert( linkResult );

	mDefaultShaderProgram->Use();
}


GraphicsDevice::~GraphicsDevice()
{
	SafeDelete( mDefaultVertexShader );
	SafeDelete( mDefaultFragmentShader );
	SafeDelete( mDefaultShaderProgram );
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


void GraphicsDevice::Clear( int mask )
{
	glClear( mask );
}


void GraphicsDevice::DrawArrays( VertexBuffer * buffer, DrawMode mode, GLint first, GLsizei count )
{
	this->PrepareVertexBuffer( buffer );
	glDrawArrays( mode, first, count );
	this->UnprepareVertexBuffer( buffer );
}


void GraphicsDevice::DrawElements( VertexBuffer * vertexBuffer, IndexBuffer * indexBuffer, DrawMode mode, GLsizei count, const GLvoid * indices )
{
	this->PrepareVertexBuffer( vertexBuffer );
	indexBuffer->Bind();

	glDrawElements( mode, count, indexBuffer->GetIndexType(), indices );

	this->UnprepareVertexBuffer( vertexBuffer );
}


void GraphicsDevice::PrepareVertexBuffer( VertexBuffer * buffer )
{
	for( int i = 0; i < buffer->GetAttributeCount(); i++ )
	{
		const VertexAttribute & attribute = buffer->GetAttribute( i );
		glEnableVertexAttribArray( attribute.Index );
		attribute.SetToBuffer( buffer );
	}
}


void GraphicsDevice::UnprepareVertexBuffer( VertexBuffer * buffer )
{
	for( int i = 0; i < buffer->GetAttributeCount(); i++ )
	{
		const VertexAttribute & attribute = buffer->GetAttribute( i );
		glDisableVertexAttribArray( attribute.Index );
	}
}


END_YAGE_NAMESPACE