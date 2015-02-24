#pragma once
#include "YageIncludes.h"

BEGIN_YAGE_NAMESPACE


struct Color
{
	float R;

	float G;

	float B;

	float A;

	Color()
	: R( 0.0f )
	, G( 0.0f )
	, B( 0.0f )
	, A( 1.0f )
	{
	}

	Color( float r, float g, float b )
		: R( r )
		, G( g )
		, B( b )
		, A( 1.0f )
	{
	}

	Color( float r, float g, float b, float a )
	: R( r )
	, G( g )
	, B( b )
	, A( a )
	{
	}

	static const Color Black;
	static const Color White;
	static const Color Red;
	static const Color Green;
	static const Color Blue;
};


END_YAGE_NAMESPACE