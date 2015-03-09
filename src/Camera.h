#pragma once
#include <assimp/camera.h>
#include "YageIncludes.h"

BEGIN_YAGE_NAMESPACE


class Camera
{
public:
	Camera();
	virtual ~Camera();

	static Camera * Load( const aiCamera * def );

	const std::string & GetName() const
	{
		return mName;
	}

	void SetName( const std::string & name )
	{
		mName = name;
	}

	const vec3 & GetPosition() const
	{
		return mPosition;
	}

	void SetPosition( const vec3 & position )
	{
		mPosition = position;
	}

	const vec3 & GetDirection() const
	{
		return mDirection;
	}

	void SetDirection( const vec3 & direction )
	{
		mDirection = direction;
	}

	const vec3 & GetUp() const
	{
		return mUp;
	}

	void SetUp( const vec3 & up )
	{
		mUp = up;
	}

	float GetFov() const
	{
		return mFov;
	}

	void SetFov( float fov )
	{
		mFov = fov;
	}

	float GetAspectRatio() const
	{
		return mAspectRatio;
	}

	void SetAspectRatio( float aspectRatio )
	{
		mAspectRatio = aspectRatio;
	}

	float GetNear() const
	{
		return mNear;
	}

	void SetNear( float near )
	{
		mNear = near;
	}

	float GetFar() const
	{
		return mFar;
	}

	void SetFar( float far )
	{
		mFar = far;
	}

	vec3 GetLeft() const;

	mat4x4 GetViewTransform() const;
	mat4x4 GetProjectionTransform() const;

private:
	std::string mName;
	vec3 mPosition;
	vec3 mDirection;
	vec3 mUp;
	float mFov;
	float mAspectRatio;
	float mNear;
	float mFar;
};


END_YAGE_NAMESPACE