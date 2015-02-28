#include "BufferBase.h"

BEGIN_YAGE_NAMESPACE


BufferBase::BufferBase( BufferType type )
: mType( type )
{
	glGenBuffers( 1, &mId );
}


BufferBase::~BufferBase()
{
	glDeleteBuffers( 1, &mId );
}


void BufferBase::Bind()
{
	glBindBuffer( mType, mId );
}


void BufferBase::SetData( GLsizeiptr size, const void * data, BufferUsage usage )
{
	this->Bind();
	glBufferData( mType, size, data, usage );
}


END_YAGE_NAMESPACE