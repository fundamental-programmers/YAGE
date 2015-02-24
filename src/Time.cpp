#include "Time.h"

BEGIN_YAGE_NAMESPACE


Time * Time::sMainTime = NULL;


Time::Time()
{
	mCurrentTime = static_cast<float>( glfwGetTime() );
	mDeltaTime = 0.0f;
	mTotalTime = 0.0f;
}


float Time::GetMainDeltaTime()
{
	return GetMain()->GetDeltaTime();
}


float Time::GetMainTotalTime()
{
	return GetMain()->GetTotalTime();
}


Time * Time::GetMain()
{
	if( sMainTime == NULL )
	{
		sMainTime = new Time();
	}
	return sMainTime;
}


void Time::Update()
{
	float time = static_cast<float>( glfwGetTime() );
	mDeltaTime = time - mCurrentTime;
	mTotalTime += mDeltaTime;
	mCurrentTime = time;
}


END_YAGE_NAMESPACE