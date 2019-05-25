#include "Logger.h"

Logger::Logger()
{
	log_file = ofstream("log.txt", ios::out);
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
	case INFO:
		log_level = "Info";
		break;
	case WARN:
		log_level = "Warning";
		break;
	case ERR:
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
	case INFO:
		log_level = "Info";
		break;
	case WARN:
		log_level = "Warning";
		break;
	case ERR:
	default:
		log_level = "Error";
		break;
	}
	log_file << log_level << " : " << error.ErrorMessage();
}
