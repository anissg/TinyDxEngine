#pragma once
#include "TinyDxEngine.h"

class Uncopyable
{
private:
	Uncopyable(const Uncopyable &val) {};
	Uncopyable& operator = (const Uncopyable &rVal) {};
protected:
	Uncopyable() {};
	virtual ~Uncopyable() {};
};

