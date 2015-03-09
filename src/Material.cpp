#include <assimp/material.h>
#include "Material.h"

BEGIN_YAGE_NAMESPACE


Material::Material()
{
}


Material::~Material()
{
}


Material * Material::Load( const aiMaterial * def )
{
	Material * material = new Material();

	aiString path;
	if( def->GetTextureCount( aiTextureType_DIFFUSE ) > 0 )
	{
		def->GetTexture( aiTextureType_DIFFUSE, 0, &path, NULL, NULL, NULL, NULL, NULL );
		Texture * texture = Texture::Load( std::string( "textures/" ) + path.C_Str() );
		assert( texture );
		material->mTextures.insert( std::make_pair( TU_Diffuse, texture ) );
	}

	return material;
}


Texture * Material::GetTexture( TextureUsage usage ) const
{
	std::map<TextureUsage, Texture*>::const_iterator it = mTextures.find( usage );
	if( it == mTextures.end() )
	{
		return NULL;
	}

	return it->second;
}


END_YAGE_NAMESPACE