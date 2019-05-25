#pragma once
#include <mmstream.h>

class Timer
{
    double m_dCurTime;
    double m_dLastTime;

public:
    Timer(void);
    ~Timer(void);
    float GetElapsedTime(void);
    double GetCurrentTime(void);
    void Reset(void);


