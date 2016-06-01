#include <cassert>
#include <fstream>
#include "MyKMP.h"

MyKMP::MyKMP(std::string patFileName, std::string inputFileName)
{
    loadInput(patFileName, pattern);
    loadInput(inputFileName, array);
    computeNext();
}

int MyKMP::match(int start)
{
    for (int i = start, j = -1; i < (int)array.size(); i++)
    {
        while (j >= 0 && pattern[j + 1] != array[i]) j = next[j];
        if (pattern[j + 1] == array[i]) j++;
        if (j + 1 == (int)pattern.size())
            return i - pattern.size() + 1;
    }
    return -1;
}

void MyKMP::computeNext()
{
    next.resize(pattern.size(), -1);
    for (int i = 1, j = -1; i < (int)pattern.size(); i++)
    {
        while (j >= 0 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[j + 1] == pattern[i]) j++;
        next[i] = j;
    }
}

void MyKMP::loadInput(std::string fileName, std::vector<int> &array)
{
    std::ifstream is(fileName);
    assert(is.good());
    int x;
    while (is >> x) array.push_back(x);
}

