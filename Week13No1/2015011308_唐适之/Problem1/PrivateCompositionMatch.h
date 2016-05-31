#ifndef PRIVATE_COMPOSITION_MATCH_H_
#define PRIVATE_COMPOSITION_MATCH_H_

#include <vector>
#include "KMP.h"

class PrivateCompositionMatch
{
public:
    PrivateCompositionMatch(std::string patFileName, std::string inputFileName)
        : mKMP(patFileName, inputFileName) {}
    
    std::vector<int> matchAll();
    
private:
    KMP mKMP;
};

#endif // PRIVATE_COMPOSITION_MATCH_H_
