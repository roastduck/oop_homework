#ifndef PRIVATE_INHERITANCE_MATCH_H_
#define PRIVATE_INHERITANCE_MATCH_H_

#include <vector>
#include "KMP.h"

class PrivateInheritanceMatch : private KMP
{
public:
    PrivateInheritanceMatch(std::string patFileName, std::string inputFileName)
        : KMP(patFileName, inputFileName) {}
    
    std::vector<int> matchAll();
};

#endif // PRIVATE_INHERITANCE_MATCH_H_
