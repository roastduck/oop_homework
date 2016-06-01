#ifndef MY_KMP_PROXY_H_
#define MY_KMP_PROXY_H_

#include <vector>
#include "MyKMP.h"

class MyKMPProxy : private MyKMP
{
public:
    MyKMPProxy(std::string patFileName, std::string inputFileName)
        : MyKMP(patFileName, inputFileName) {}
    
    std::vector<int> matchAll();
};

#endif // MY_KMP_PROXY_H_
