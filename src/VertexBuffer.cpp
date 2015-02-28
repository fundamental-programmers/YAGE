#include "VertexBuffer.h"

BEGIN_YAGE_NAMESPACE


VertexBuffer::VertexBuffer()
: BufferBase( BT_Vertex )
{
}


VertexBuffer::~VertexBuffer()
{
}


size_t VertexBuffer::GetAttributeCount() const
{
	return mAttributes.size();
}


const VertexAttribute& VertexBuffer::GetAttribute( size_t index ) const
{
	return mAttributes[index];
}


void VertexBuffer::AddAttribute( const VertexAttribute & attribute )
{
	mAttributes.push_back( attribute );
}


END_YAGE_NAMESPACE