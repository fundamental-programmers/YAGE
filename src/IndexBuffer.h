#pragma once
#include "YageIncludes.h"
#include "BufferBase.h"
#include "IndexType.h"

BEGIN_YAGE_NAMESPACE


class IndexBuffer : public BufferBase
{
public:
	IndexBuffer();

	IndexType GetIndexType() const
	{
		return mIndexType;
	}

	void SetIndexType( IndexType indexType )
	{
		mIndexType = indexType;
	}

private:
	IndexType mIndexType;
};


END_YAGE_NAMESPACE