#pragma once

#include "platform/CCPlatformMacros.h"
#include "base/CCRef.h"

namespace cocos2d
{
template <typename T>
class RefHolder
{
	T mObject;

public:
	using RefType = T;

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

	RefHolder(T object)
		: mObject(nullptr)
	{
		setObject(object);
	}
	RefHolder()
		: mObject(nullptr)
	{
	}
	RefHolder(const RefHolder &other)
		: RefHolder(other.mObject)
	{
	}
	RefHolder(RefHolder &&other)
		: mObject(other.mObject)
	{
		other.mObject = nullptr;
	}
	~RefHolder()
	{
		CC_SAFE_RELEASE(mObject);
	}

	inline bool operator==(const RefHolder &other)
	{
		return other.mObject == mObject;
	}
	inline bool operator!=(const RefHolder &other)
	{
		return !operator==(other);
	}

	RefHolder &operator=(const RefHolder &other)
	{
		setObject(other.mObject);
		return *this;
	}

	RefHolder &operator=(RefHolder &&other)
	{
		if (other.mObject == mObject)
		{
			CC_SAFE_RELEASE_NULL(other.mObject);
		} else
		{
			CC_SAFE_RELEASE(mObject);
			mObject = other.mObject;
			other.mObject = nullptr;
		}
		return *this;
	}
};

using AnyObjectHolder = RefHolder<Ref *>;
}
