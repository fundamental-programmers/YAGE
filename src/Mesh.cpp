#include <glob.h>
#include <iostream>
#include "Mesh.h"
#include "MeshVertexAttribute.h"
#include "GraphicsDevice.h"

BEGIN_YAGE_NAMESPACE


Mesh::Mesh()
{
	mVertexBuffer = new VertexBuffer();
	mIndexBuffer = new IndexBuffer();
}


Mesh::~Mesh()
{
	SafeDelete( mIndexBuffer );
	SafeDelete( mVertexBuffer );
}


Mesh * Mesh::Load( const aiMesh * meshDef )
{
	size_t stride = CalculateStride( meshDef );
	size_t size = stride * meshDef->mNumVertices;
	char * buffer = new char[size];

	RearrangeData( meshDef, buffer, size );

	Mesh * mesh = new Mesh();
	SetVertexData( meshDef, buffer, stride, mesh );
	SetFaceData( meshDef, mesh );

	delete[] buffer;
	return mesh;
}


void Mesh::Draw( GraphicsDevice * graphics )
{
	graphics->DrawElements( mVertexBuffer, mIndexBuffer, DM_Triangles, mFaceCount * 3, 0 );
}


size_t Mesh::CalculateStride( const aiMesh * meshDef )
{
	size_t size = 0;
	if( meshDef->HasPositions() )
	{
		size += sizeof( float ) * 3;
	}
	if( meshDef->HasNormals() )
	{
		size += sizeof( float ) * 3;
	}
	if( meshDef->HasTextureCoords( 0 ) )
	{
		size += sizeof( float ) * 3;
	}
	if( meshDef->HasVertexColors( 0 ) )
	{
		size += sizeof( float ) * 4;
	}
	if( meshDef->HasTangentsAndBitangents() )
	{
		size += sizeof( float ) * 3 * 2;
	}
	return size;
}


void Mesh::RearrangeData( const aiMesh * meshDef, char * buffer, size_t bufferSize )
{
	char * current = buffer;
	for( int i = 0; i < meshDef->mNumVertices; ++i )
	{
		if( meshDef->HasPositions() )
		{
			size_t size = sizeof( float ) * 3;
			memcpy( current, &meshDef->mVertices[i], size );
			current += size;

			const aiVector3D & v = meshDef->mVertices[i];
		}
		if( meshDef->HasNormals() )
		{
			size_t size = sizeof( float ) * 3;
			memcpy( current, &meshDef->mNormals[i], size );
			current += size;
		}
		if( meshDef->HasTextureCoords( 0 ) )
		{
			size_t size = sizeof( float ) * 3;
			memcpy( current, &meshDef->mTextureCoords[i], size );
			current += size;
		}
		if( meshDef->HasVertexColors( 0 ) )
		{
			size_t size = sizeof( float ) * 4;
			memcpy( current, &meshDef->mColors[i], size );
			current += size;
		}
		if( meshDef->HasTangentsAndBitangents() )
		{
			memcpy( current, &meshDef->mTangents[i], sizeof( float ) * 3 );
			memcpy( current, &meshDef->mBitangents[i], sizeof( float ) * 3 );
			current += sizeof( float ) * 3 * 2;
		}
	}

	assert( current - buffer == bufferSize );
}


void Mesh::SetVertexData( const aiMesh * meshDef, char * buffer, size_t stride, Mesh * mesh )
{
	mesh->mVertexBuffer->SetData( stride * meshDef->mNumVertices, buffer, BU_StaticDraw );

	size_t current = 0;
	if( meshDef->HasPositions() )
	{
		mesh->mVertexBuffer->AddAttribute( VertexAttribute( MVA_Position, 3, VAT_Float, false, stride, current ) );
		current += sizeof( float ) * 3;
	}
	if( meshDef->HasNormals() )
	{
		mesh->mVertexBuffer->AddAttribute( VertexAttribute( MVA_Normal, 3, VAT_Float, true, stride, current ) );
		current += sizeof( float ) * 3;
	}
	if( meshDef->HasTextureCoords( 0 ) )
	{
		mesh->mVertexBuffer->AddAttribute( VertexAttribute( MVA_TexCoord, 3, VAT_Float, false, stride, current ) );
		current += sizeof( float ) * 3;
	}
	if( meshDef->HasVertexColors( 0 ) )
	{
		mesh->mVertexBuffer->AddAttribute( VertexAttribute( MVA_Color, 3, VAT_Float, false, stride, current ) );
		current += sizeof( float ) * 4;
	}
	if( meshDef->HasTangentsAndBitangents() )
	{
		mesh->mVertexBuffer->AddAttribute( VertexAttribute( MVA_Tangent, 3, VAT_Float, false, stride, current ) );
		current += sizeof( float ) * 3;
		mesh->mVertexBuffer->AddAttribute( VertexAttribute( MVA_Bitangent, 3, VAT_Float, false, stride, current ) );
	}
}


void Mesh::SetFaceData( const aiMesh * meshDef, Mesh * mesh )
{
	assert( meshDef->HasFaces() );
	assert( meshDef->mPrimitiveTypes == aiPrimitiveType_TRIANGLE );
	mesh->mFaceCount = meshDef->mNumFaces;

	unsigned int * indices = new unsigned int[meshDef->mNumFaces * 3];
	unsigned int * current = indices;
	for( int i = 0; i < meshDef->mNumFaces; ++i )
	{
		const aiFace & face = meshDef->mFaces[i];
		assert( face.mNumIndices == 3 );

		memcpy( current, face.mIndices, sizeof( unsigned int ) * 3 );
		current += 3;
	}

	mesh->mIndexBuffer->SetData( sizeof( unsigned int ) * meshDef->mNumFaces * 3, indices, BU_StaticDraw );
	mesh->mIndexBuffer->SetIndexType( IT_UnsignedInt );

	delete[] indices;
}


END_YAGE_NAMESPACE