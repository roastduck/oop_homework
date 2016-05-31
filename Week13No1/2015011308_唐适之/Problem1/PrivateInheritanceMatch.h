#ifndef PRIVATE_INHERITANCE_MATCH_H_
#define PRIVATE_INHERITANCE_MATCH_H_

#include <vector>
#include "KMP.h"

class PrivateInheritanceMatch : private KMP
{
public:
    PrivateInheritanceMatch(std::string patFileName, std::string inputFileName)
        : KMP(patFileName, inputFileName) {}
    
    std::vector<int> matchAll()
    {
        std::vector<int> matches;
        int pos = 0;
        while (~(pos = match(pos)))
            matches.push_back(pos), pos++;
        return matches;
    }
};

#endif // PRIVATE_INHERITANCE_MATCH_H_
