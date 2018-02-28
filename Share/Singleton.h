#pragma once

/************************************************************************/
/* @单件模板类                                                            
/* 1.单件类应该public继承此类，并构造函数和析构函数设为私有
/* 2.拷贝构造，= 为delete
/* 3.声明处SINGLETION_FRIEND_CLASS_REGISTER(T)
/************************************************************************/
template<typename T>
class CSingleton
{
public:
	static T* GetInstance()
	{
		if (mInstance == nullptr)
			mInstance = new T;
		return mInstance;
	}

	static void DestroyInstance()
	{
		if (mInstance)
		{
			delete mInstance;
			mInstance = nullptr;
		}
	}
protected:
	CSingleton() = default;
	virtual ~CSingleton() = default;

private:
	static T* mInstance;
};

#define SINGLETION_FRIEND_CLASS_REGISTER(T) \
public: \
	friend class CSingleton<T>;

template<typename T>
T* CSingleton<T>::mInstance = 0;