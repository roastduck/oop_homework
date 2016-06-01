#include "KMPBase.h"

KMPBase::KMPBase(std::string patFileName, std::string inputFileName)
    : mKMP(patFileName, inputFileName)
{}

KMPBase::~KMPBase() {}

int KMPBase::match(int start)
{
    int pos = mKMP.match(start), ret = pos;
    while (~pos)
    {
        if (! getMatch(pos)) return ret;
        pos = mKMP.match(pos + 1);
    }
    return ret;
}
