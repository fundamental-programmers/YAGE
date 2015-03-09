#pragma once
#include "YageIncludes.h"
#include <assimp/material.h>
#include "Texture.h"
#include "TextureUsage.h"

BEGIN_YAGE_NAMESPACE


class Material
{
public:
	Material();
	virtual ~Material();

	static Material * Load( const aiMaterial * def );

	Texture * GetTexture( TextureUsage usage ) const;

private:
	std::map<TextureUsage, Texture*> mTextures;
};


END_YAGE_NAMESPACE