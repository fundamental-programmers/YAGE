#include "Camera.h"

BEGIN_YAGE_NAMESPACE


Camera::Camera()
: mPosition( 0.0f, 0.0f, 0.0f )
, mTarget( 0.0f, -1.0f, 0.0f )
, mUp( 0.0f, 1.0f, 0.0f )
{
}


Camera::~Camera()
{
}


vec3 Camera::GetLeft() const
{
	return cross( mUp, this->GetForward() );
}


vec3 Camera::GetForward() const
{
	return normalize( mTarget - mPosition );
}


mat4x4 Camera::GetViewTransform() const
{
	return lookAt( mPosition, mTarget, mUp );
}


mat4x4 Camera::GetProjectionTransform() const
{
	return mProjectionTransform;
}


void Camera::SetPerspective( float fov, float aspectRatio, float near, float far )
{
	mProjectionTransform = perspective( fov, aspectRatio, near, far );
}


END_YAGE_NAMESPACE