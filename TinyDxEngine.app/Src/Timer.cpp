#include "Timer.h"

Timer::Timer(void)
{
    m_dCurTime = 0;
    m_dLastTime = 0;
}


Timer::~Timer(void)
{
}


double Timer::GetElapsedTime()
{
    double elapsed;
    if (m_dCurTime == 0 && m_dLastTime == 0)
    {
        m_dLastTime = timeGetTime();
        return 0;
    }
    m_dCurTime = timeGetTime();
    elapsed = (float)((m_dCurTime - m_dLastTime) / 1000);
    m_dLastTime = m_dCurTime;
    return elapsed;
}


double Timer::GetCurrentTime()
{
    m_dCurTime = timeGetTime();
    return m_dCurTime;
}


void Timer::Reset()
{
    m_dCurTime = m_dLastTime = 0;
}
