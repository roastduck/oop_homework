#ifndef PUBLIC_COMPOSITION_MATCH_H_
#define PUBLIC_COMPOSITION_MATCH_H_

#include "KMP.h"

class PublicCompositionMatch
{
public:
    PublicCompositionMatch(std::string patFileName, std::string inputFileName)
        : mKMP(patFileName, inputFileName) {}
    
    KMP mKMP;
};

#endif // PUBLIC_COMPOSITION_MATCH_H_
