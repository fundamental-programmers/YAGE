#include "Texture.h"
#include <ImageMagick/Magick++.h>
#include <strings.h>

BEGIN_YAGE_NAMESPACE


Texture::Texture()
: mId( 0 )
{
}


Texture::~Texture()
{
}


Texture * Texture::Load( const std::string & filename )
{
	Magick::Image * image = NULL;
	Magick::Blob blob;
	try
	{
		image = new Magick::Image( filename );
		image->write( &blob, "RGBA" );
	}
	catch( ... )
	{
		SafeDelete( image );
		return NULL;
	}

	Texture * texture = new Texture();
	glGenTextures( 1, &texture->mId );
	glBindTexture( GL_TEXTURE_2D, texture->mId );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, static_cast<GLsizei>( image->columns() ), static_cast<GLsizei>( image->rows() ), 0, GL_RGBA, GL_UNSIGNED_BYTE, blob.data() );

	SafeDelete( image );

	texture->SetMinFilter( TF_Linear );
	texture->SetMagFilter( TF_Linear );

	return texture;
}


void Texture::SetMinFilter( TextureFilter filter )
{
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter );
}


void Texture::SetMagFilter( TextureFilter filter )
{
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter );
}


void Texture::SetWrapS( TextureWrap wrap )
{
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap );
}


void Texture::SetWrapT( TextureWrap wrap )
{
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap );
}


void Texture::Bind( GLuint index )
{
	glActiveTexture( GL_TEXTURE0 + index );
	glBindTexture( GL_TEXTURE_2D, mId );
}


END_YAGE_NAMESPACE