#pragma once

class Uncopyable
{
private:
	Uncopyable(const Uncopyable &val) {};
	Uncopyable& operator = (const Uncopyable &rVal) {};
protected:
	Uncopyable() {};
	virtual ~Uncopyable() {};
};

