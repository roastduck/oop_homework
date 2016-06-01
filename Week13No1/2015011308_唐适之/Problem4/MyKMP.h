// the same as KMP.h

#ifndef MY_KMP_H_
#define MY_KMP_H_
#include <string>
#include <vector>

class MyKMP
{
    public:
        MyKMP(std::string patFileName, std::string inputFileName);
        // search the pattern "pattern_" in array "array_" starting from the index "start", i.e., starting from the element array_[start]
        // If found a match, then returns the index of the match; otherwise, -1 is returned
        int match(int start = 0);
    protected:
        std::vector<int> array;   // stores the integer (0-1) array
        std::vector<int> pattern; // stores the integer (0-1) pattern to be searched
        std::vector<int> next;    // for KMP algorithm
        void computeNext();        // for KMP algorithm
        // load the input from the file
        void loadInput(std::string fileName, std::vector<int> &array); // load in the input file
};

#endif // MY_KMP_H_
