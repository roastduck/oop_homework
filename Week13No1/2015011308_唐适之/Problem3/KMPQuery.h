#ifndef KMPQUERY_H
#define KMPQUERY_H
#include <KMPBase.h>

// NOTE: This file MUST NOT be modified.
// KMPQuery.cpp needs to be implemented for compiling the program

class KMPQuery : public KMPBase
{
    public:
        // patFileName: file name storing the 0-1 string pattern
        // arrayFileName: fileName storing the 0-1 array to be matched
        // queryNum: we only want to find the first queryNum matches (initialize query_num_ by this argument)
        KMPQuery(std::string patFileName, std::string arrayFileName, int queryNum);
        bool getMatch(int index); // obtain a match here
        virtual ~KMPQuery();
        // print out all the matches using cout or using a file (filename is "matches.txt")
        void printMatches();

    protected:
    private:
        // stores all the matches found
        // the total number of matches should be less than or equal to query_num_
        std::vector<int> matches_;
        // We only want to find the first query_num_ matches
        int query_num_;
};

#endif // KMPQUERY_H
