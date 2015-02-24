#pragma once
#include "YageIncludes.h"
#include "Color.h"
#include "BufferClearMask.h"

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
};


END_YAGE_NAMESPACE