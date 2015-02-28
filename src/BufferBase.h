#pragma once
#include "YageIncludes.h"
#include "BufferType.h"
#include "BufferUsage.h"

BEGIN_YAGE_NAMESPACE


class BufferBase
{
protected:
	BufferBase( BufferType type );
	virtual ~BufferBase();

public:
	BufferType GetType() const
	{
		return mType;
	}

	void Bind();
	void SetData( GLsizeiptr size, const void * data, BufferUsage usage );

protected:
	BufferType mType;
	GLuint mId;
};


END_YAGE_NAMESPACE