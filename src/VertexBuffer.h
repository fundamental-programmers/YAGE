#pragma once
#include "YageIncludes.h"
#include "BufferBase.h"
#include "VertexAttribute.h"

BEGIN_YAGE_NAMESPACE


class VertexBuffer : public BufferBase
{
public:
	VertexBuffer();
	virtual ~VertexBuffer();

	size_t GetAttributeCount() const;
	const VertexAttribute & GetAttribute( size_t index ) const;

	void AddAttribute( const VertexAttribute & attribute );

private:
	std::vector<VertexAttribute> mAttributes;
};


END_YAGE_NAMESPACE