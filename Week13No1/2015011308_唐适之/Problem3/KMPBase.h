#ifndef KMPBASE_H
#define KMPBASE_H
#include <string>
#include <vector>

// NOTE: You need to implement KMPBase.cpp for compiling the program

// You need to include this header from Problem 1 if you want to use the library
#include "MyKMP.h"

class KMPBase
{
    public:
        KMPBase(std::string patFileName, std::string inputFileName);
        virtual ~KMPBase();
        // start to match the pattern from array[start]
        // @return : the 1st match
        int match(int start = 0);
        // pure virtual function for passing each found matching position
        // @return : true = continue, false = stop
        virtual bool getMatch(int index) = 0;
        // You may add member functions and member variables for the matching process
    protected:
    private:
        KMPBase(const KMPBase& other);
        KMPBase& operator=(const KMPBase& other);
        
        MyKMP mKMP;
};

#endif // KMPBASE_H
