#pragma once
#include "YageIncludes.h"

BEGIN_YAGE_NAMESPACE


class Camera
{
public:
	Camera();
	virtual ~Camera();

	const vec3 & GetPosition() const
	{
		return mPosition;
	}

	void SetPosition( const vec3 & position )
	{
		mPosition = position;
	}

	const vec3 & GetTarget() const
	{
		return mTarget;
	}

	void SetTarget( const vec3 & target )
	{
		mTarget = target;
	}

	const vec3 & GetUp() const
	{
		return mUp;
	}

	void SetUp( const vec3 & up )
	{
		mUp = up;
	}

	vec3 GetLeft() const;
	vec3 GetForward() const;

	mat4x4 GetViewTransform() const;
	mat4x4 GetProjectionTransform() const;

	void SetPerspective( float fov, float aspectRatio, float near, float far );

private:
	vec3 mPosition;
	vec3 mTarget;
	vec3 mUp;
	mat4x4 mProjectionTransform;
};


END_YAGE_NAMESPACE