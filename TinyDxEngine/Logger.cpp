#include "TinyDxEngine.h"
#include "Logger.h"


Logger::Logger()
{
	log_file = ofstream("log.txt");
}


Logger::~Logger()
{
	log_file.close();
}

void Logger::Log(string message, int level)
{
	string log_level;
	switch (level)
	{
	case 0:
		log_level = "Info";
		break;
	case 1:
		log_level = "Warning";
		break;
	case 2:
	default:
		log_level = "Error";
		break;
	}
	log_file << log_level << " : " << message;
}

void Logger::Log(HRESULT hr, int level)
{
	_com_error error(hr);
	string log_level;
	switch (level)
	{
	case 0:
		log_level = "Info";
		break;
	case 1:
		log_level = "Warning";
		break;
	case 2:
	default:
		log_level = "Error";
		break;
	}
	log_file << log_level << " : " << error.ErrorMessage();
}
