#ifndef TIMER_H_
#define TIMER_H_

#include <ctime>
#include <iostream>
#include "Sorter.h"

class Timer
{
public:
    void run(Sorter *sorter, std::vector<Student*> &students)
    {
        clock_t timeSt = clock();
        sorter->sort(students);
        clock_t timeEn = clock();
        std::cout << "Time = " << (result = (double)(timeEn - timeSt) / CLOCKS_PER_SEC) << "(s)" << std::endl;
    }
    
    double getResult() { return result; }

private:
    double result;
};

#endif // TIMER_H_

