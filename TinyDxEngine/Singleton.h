#pragma once
#include "TinyDxEngine.h"
#include "Uncopyable.h"

template <class T>
class Singleton : public Uncopyable
{
public:
	static T& get()
	{
		static T instance;
		return instance;
	}
};