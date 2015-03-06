#pragma once
#include "YageIncludes.h"
#include "TextureFilter.h"
#include "TextureWrap.h"

BEGIN_YAGE_NAMESPACE


class Texture
{
public:
	Texture();
	virtual ~Texture();

	static Texture * Load( const std::string & filename );

	GLuint _GetId() const
	{
		return mId;
	}

	void SetMinFilter( TextureFilter filter );
	void SetMagFilter( TextureFilter filter );
	void SetWrapS( TextureWrap wrap );
	void SetWrapT( TextureWrap wrap );

	void Bind( GLuint index );

private:
	GLuint mId;
};


END_YAGE_NAMESPACE