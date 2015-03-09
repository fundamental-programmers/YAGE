#pragma once
#include <assimp/mesh.h>
#include <glob.h>
#include "YageIncludes.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "GraphicsDevice.h"
#include "Material.h"

BEGIN_YAGE_NAMESPACE


class Scene;


class Mesh
{
public:
	Mesh();
	virtual ~Mesh();

	static Mesh * Load( const aiMesh * meshDef, Scene * scene );

	void Draw( GraphicsDevice * graphics );

private:
	static size_t CalculateStride( const aiMesh * meshDef );
	static void RearrangeData( const aiMesh * meshDef, char * buffer, size_t bufferSize );
	static void SetVertexData( const aiMesh * meshDef, char * buffer, size_t stride, Mesh * mesh );
	static void SetFaceData( const aiMesh * meshDef, Mesh * mesh );

	VertexBuffer * mVertexBuffer;
	IndexBuffer * mIndexBuffer;
	size_t mFaceCount;
	Material * mMaterial;
};


END_YAGE_NAMESPACE