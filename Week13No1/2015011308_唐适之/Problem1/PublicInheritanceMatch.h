#ifndef PUBLIC_INHERITANCE_MATCH_H_
#define PUBLIC_INHERITANCE_MATCH_H_

#include "KMP.h"

class PublicInheritanceMatch : public KMP
{
public:
    PublicInheritanceMatch(std::string patFileName, std::string inputFileName)
        : KMP(patFileName, inputFileName) {}
};

#endif // PUBLIC_INHERITANCE_MATCH_H_
