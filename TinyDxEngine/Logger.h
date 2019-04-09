#pragma once
#include "TinyDxEngine.h"

using namespace std;

class Logger : public Singleton<Logger>
{
	ofstream log_file;
public:
	Logger();
	~Logger();

	void Log(string message, int level = 0);
	void Log(HRESULT hr, int level = 0);
};

