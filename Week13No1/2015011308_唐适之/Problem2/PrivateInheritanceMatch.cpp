#include "PrivateInheritanceMatch.h"

std::vector<int> PrivateInheritanceMatch::matchAll()
{
    std::vector<int> matches;
    int pos = 0;
    while (~(pos = match(pos)))
        matches.push_back(pos), pos++;
    return matches;
}
