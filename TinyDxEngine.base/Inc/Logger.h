#pragma once
#include "Singleton.h"
#include <string>
#include <iostream>
#include <fstream>
#include <comdef.h>

using namespace std;

enum
{
	INFO = 0,
	WARN = 1,
	ERR = 2
};

class Logger : public Singleton<Logger>
{
private:
	ofstream log_file;
public:
    Logger();
    ~Logger();
	void Log(string message, int level = 0);
	void Log(HRESULT hr, int level = 0);
};

