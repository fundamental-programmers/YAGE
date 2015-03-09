#pragma once
#include "YageIncludes.h"
#include "Camera.h"
#include "Mesh.h"
#include "Material.h"
#include "Texture.h"

BEGIN_YAGE_NAMESPACE


class Scene
{
public:
	Scene();
	virtual ~Scene();

	static Scene * Load( const std::string & filename );

	size_t GetCameraCount() const;
	Camera * GetCamera( size_t index ) const;

	size_t GetMeshCount() const;
	Mesh * GetMesh( size_t index ) const;

	size_t GetMaterialCount() const;
	Material * GetMaterial( size_t index ) const;

	void Draw( GraphicsDevice * graphics );

private:
	std::vector<Camera*> mCameras;
	std::vector<Mesh*> mMeshes;
	std::vector<Material*> mMaterials;
};


END_YAGE_NAMESPACE