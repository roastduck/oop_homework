#ifndef PRIVATE_COMPOSITION_MATCH_H_
#define PRIVATE_COMPOSITION_MATCH_H_

#include <vector>
#include "KMP.h"

class PrivateCompositionMatch
{
public:
    PrivateCompositionMatch(std::string patFileName, std::string inputFileName)
        : mKMP(patFileName, inputFileName) {}
    
    std::vector<int> matchAll()
    {
        std::vector<int> matches;
        int pos = 0;
        while (~(pos = mKMP.match(pos)))
            matches.push_back(pos), pos++;
        return matches;
    }
    
private:
    KMP mKMP;
};

#endif // PRIVATE_COMPOSITION_MATCH_H_
