#pragma once
#include <mmstream.h>

class Timer
{
    double m_dCurTime;
    double m_dLastTime;

public:
    Timer(void);
    ~Timer(void);
    double GetElapsedTime();
    double GetCurrentTime();
    void Reset(void);;
};