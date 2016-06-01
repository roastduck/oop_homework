#include <iostream>
#include "KMPQuery.h"
    
KMPQuery::KMPQuery(std::string patFileName, std::string arrayFileName, int queryNum)
    : KMPBase(patFileName, arrayFileName), query_num_(queryNum)
{}

KMPQuery::~KMPQuery() {}

bool KMPQuery::getMatch(int index)
{
    matches_.push_back(index);
    return (int)matches_.size() < query_num_;
}

void KMPQuery::printMatches()
{
    std::cout << "Matches at : ";
    for (int item : matches_)
        std::cout << item << ' ';
    std::cout << std::endl;
}

