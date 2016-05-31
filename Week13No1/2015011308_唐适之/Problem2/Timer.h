#ifndef TIMER_H_
#define TIMER_H_

#include <cassert>
#include <vector>
#include <sys/time.h>
#include <sys/timeb.h>
#include <windows.h>

/// Timer for matching algorithm T
template <class T>
class Timer
{
public:
    Timer()
    {
        if (! QueryPerformanceFrequency(&winFreq)) assert(false);
    }
    
    /// measure time consumption of one match
    /// @1 : pattern file
    /// @2 : content array file
    /// @return : matching result
    std::vector<int> measure(const std::string &patFileName, const std::string &inputFileName)
    {
        obj = new T(patFileName, inputFileName);
        if (! QueryPerformanceCounter(&winStart)) assert(false);
        std::vector<int> ret = obj->matchAll();
        if (! QueryPerformanceCounter(&winEnd)) assert(false);
        return ret;
    }
    
    /// get measure result
    double getTime() const
    {
        return (double)(winEnd.QuadPart - winStart.QuadPart) / winFreq.QuadPart;
    }

private:
    T *obj;
    LARGE_INTEGER winFreq, winStart, winEnd;
};

#endif // TIMER_H_
