#pragma once
#include "YageIncludes.h"

BEGIN_YAGE_NAMESPACE


class Time
{
public:
	Time();

	float GetDeltaTime() const
	{
		return mDeltaTime;
	}

	float GetTotalTime() const
	{
		return mTotalTime;
	}

	void Update();

	static float GetMainDeltaTime();
	static float GetMainTotalTime();

	static Time * GetMain();

private:
	static Time * sMainTime;

	float mCurrentTime;
	float mDeltaTime;
	float mTotalTime;
};


END_YAGE_NAMESPACE