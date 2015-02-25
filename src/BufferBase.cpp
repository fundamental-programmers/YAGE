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


void BufferBase::SetData( unsigned long size, const void * data, BufferUsage usage )
{
	glBindBuffer( mType, mId );
	glBufferData( mType, size, data, usage );
}


END_YAGE_NAMESPACE