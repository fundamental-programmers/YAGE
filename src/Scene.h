#pragma once
#include "YageIncludes.h"
#include "Camera.h"
#include "Mesh.h"

BEGIN_YAGE_NAMESPACE


class Scene
{
public:
	Scene();

	static Scene * Load( const std::string & filename );

private:
	std::vector<Camera*> mCameras;
	std::vector<Mesh*> mMeshes;
};


END_YAGE_NAMESPACE