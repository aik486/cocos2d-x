#pragma once

#include "platform/CCPlatformMacros.h"

namespace cocos2d
{
template <typename T>
class CCObjectHolder
{
	T mObject;

public:
	inline T object() const
	{
		return mObject;
	}

	void setObject(T obj)
	{
		if (mObject == obj)
			return;

		CC_SAFE_RELEASE(mObject);
		mObject = obj;
		CC_SAFE_RETAIN(mObject);
	}

	CCObjectHolder(T object)
		: mObject(nullptr)
	{
		setObject(object);
	}
	CCObjectHolder()
		: mObject(nullptr)
	{
	}
	CCObjectHolder(const CCObjectHolder &other)
		: CCObjectHolder(other.mObject)
	{
	}
	CCObjectHolder(CCObjectHolder &&other)
		: mObject(other.mObject)
	{
		other.mObject = nullptr;
	}
	~CCObjectHolder()
	{
		CC_SAFE_RELEASE(mObject);
	}

	inline bool operator==(const CCObjectHolder &other)
	{
		return other.mObject == mObject;
	}
	inline bool operator!=(const CCObjectHolder &other)
	{
		return !operator==(other);
	}

	CCObjectHolder &operator=(const CCObjectHolder &other)
	{
		setObject(other.mObject);
		return *this;
	}

	CCObjectHolder &operator=(CCObjectHolder &&other)
	{
		if (other.mObject == mObject)
		{
			CC_SAFE_RELEASE_NULL(other.mObject);
		} else
		{
			mObject = other.mObject;
			other.mObject = nullptr;
		}
		return *this;
	}
};
}
