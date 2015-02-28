#include "VertexAttribute.h"
#include "VertexBuffer.h"

BEGIN_YAGE_NAMESPACE


VertexAttribute::VertexAttribute()
{
}


VertexAttribute::VertexAttribute( GLuint index, GLint size, VertexAttributeType type, GLboolean normalized, GLsizei stride, const GLvoid * pointer )
: Index( index )
, Size( size )
, Type( type )
, Normalized( normalized )
, Stride( stride )
, Pointer( pointer )
{
}


void VertexAttribute::SetToBuffer( VertexBuffer * buffer ) const
{
	buffer->Bind();
	glVertexAttribPointer( this->Index, this->Size, this->Type, this->Normalized, this->Stride, this->Pointer );
}


END_YAGE_NAMESPACE