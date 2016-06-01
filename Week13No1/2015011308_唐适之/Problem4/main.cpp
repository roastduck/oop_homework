#include <ctime>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "KMPProxy.h"
#include "MyKMPProxy.h"
#include "Timer.h"

const char patternFile[] = "pattern.txt";
const char arrayFile[] = "array.txt";
const int patternLen = 10;
const int arrayLen = 1e6;

void genRandFile(const char filename[], int length)
{
    std::ofstream os(filename);
    for (int i = 0; i < length; i++)
        os << rand() % 2 << ' ';
    os << std::endl;
}

int main()
{
#ifdef NDEBUG
    srand(time(0));
#endif
    genRandFile(patternFile, patternLen);
    genRandFile(arrayFile, arrayLen);
    
    Timer<KMPProxy> timerKMP;
    Timer<MyKMPProxy> timerMyKMPProxy;
    std::vector<int> retKMP = timerKMP.measure(patternFile, arrayFile);
    std::vector<int> retMyKMPProxy = timerMyKMPProxy.measure(patternFile, arrayFile);
    assert(retKMP == retMyKMPProxy);
    double t1 = timerKMP.getTime(), t2 = timerMyKMPProxy.getTime();
    
    std::cout << "Matches = ";
    for (const int item : retKMP) std::cout << item << ' ';
    std::cout << std::endl;
    std::cout << "t1 (KMP reuse) = " << t1 << std::endl;
    std::cout << "t2 (MyKMP) = " << t2 << std::endl;
    std::cout << "Improvement = " << (t1 - t2) / t1 << std::endl;
    // The pattern is too short, so brute force is faster.
    return 0;
}

