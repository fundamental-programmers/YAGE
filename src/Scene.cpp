#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <strings.h>
#include "Scene.h"

BEGIN_YAGE_NAMESPACE


Scene::Scene()
{
}


Scene::~Scene()
{
}


Scene * Scene::Load( const std::string & filename )
{
	Assimp::Importer importer;
	const aiScene * sceneDef = importer.ReadFile( filename.c_str(), aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs );

	Scene * scene = new Scene();

	for( int i = 0; i < sceneDef->mNumCameras; ++i )
	{
		scene->mCameras.push_back( Camera::Load( sceneDef->mCameras[i] ) );
	}

	for( int i = 0; i < sceneDef->mNumMaterials; ++i )
	{
		scene->mMaterials.push_back( Material::Load( sceneDef->mMaterials[i] ) );
	}

	for( int i = 0; i < sceneDef->mNumMeshes; ++i )
	{
		scene->mMeshes.push_back( Mesh::Load( sceneDef->mMeshes[i], scene ) );
	}

	return scene;
}


size_t Scene::GetCameraCount() const
{
	return mCameras.size();
}


Camera * Scene::GetCamera( size_t index ) const
{
	return mCameras[index];
}


size_t Scene::GetMeshCount() const
{
	return mMeshes.size();
}


Mesh * Scene::GetMesh( size_t index ) const
{
	return mMeshes[index];
}


size_t Scene::GetMaterialCount() const
{
	return mMaterials.size();
}


Material * Scene::GetMaterial( size_t index ) const
{
	return mMaterials[index];
}


void Scene::Draw( GraphicsDevice * graphics )
{
	for( int i = 0; i < mMeshes.size(); ++i )
	{
		mMeshes[i]->Draw( graphics );
	}
}


END_YAGE_NAMESPACE