#include "PrivateCompositionMatch.h"

std::vector<int> PrivateCompositionMatch::matchAll()
{
    std::vector<int> matches;
    int pos = 0;
    while (~(pos = mKMP.match(pos)))
        matches.push_back(pos), pos++;
    return matches;
}

