#ifndef KMP_PROXY_H_
#define KMP_PROXY_H_

#include <vector>
#include "KMP.h"

class KMPProxy : private KMP
{
public:
    KMPProxy(std::string patFileName, std::string inputFileName)
        : KMP(patFileName, inputFileName) {}
    
    std::vector<int> matchAll();
};

#endif // KMP_PROXY_H_
