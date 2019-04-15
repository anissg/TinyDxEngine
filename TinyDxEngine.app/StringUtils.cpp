#include "pch.h"
#include "StringUtils.h"

wstring StringUtils::StringToWString(string str)
{
	return wstring(str.begin(), str.end());
}
