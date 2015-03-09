#include "Camera.h"
#include "Utilities.h"

BEGIN_YAGE_NAMESPACE


Camera::Camera()
: mPosition( 0.0f, 0.0f, 0.0f )
, mDirection( 0.0f, 0.0f, -1.0f )
, mUp( 0.0f, 1.0f, 0.0f )
, mFov( pi<float>() / 4.0f )
, mAspectRatio( 1.666667f )
, mNear( 0.1f )
, mFar( 1000.0f )
{
}


Camera::~Camera()
{
}


Camera * Camera::Load( const aiCamera * def )
{
	Camera * camera = new Camera();
	camera->SetName( def->mName.C_Str() );
	camera->SetPosition( Utilities::ToVector3( def->mPosition ) );
	camera->SetDirection( Utilities::ToVector3( def->mLookAt ) );
	camera->SetUp( Utilities::ToVector3( def->mUp ) );
	camera->SetFov( def->mHorizontalFOV );
	camera->SetAspectRatio( def->mAspect );
	camera->SetNear( def->mClipPlaneNear );
	camera->SetFar( def->mClipPlaneFar );
	return camera;
}


vec3 Camera::GetLeft() const
{
	return cross( mUp, this->GetDirection() );
}


mat4x4 Camera::GetViewTransform() const
{
	return lookAt( mPosition, mPosition + mDirection, mUp );
}


mat4x4 Camera::GetProjectionTransform() const
{
	return perspective( mFov, mAspectRatio, mNear, mFar );
}


END_YAGE_NAMESPACE