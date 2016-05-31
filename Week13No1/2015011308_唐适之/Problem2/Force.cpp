#include <cassert>
#include <fstream>
#include <algorithm>
#include "Force.h"

Force::Force(const std::string &patFileName, const std::string &inputFileName)
{
    loadInput(patFileName, pattern);
    loadInput(inputFileName, array);
}

std::vector<int> Force::matchAll()
{
    std::vector<int> ret;
    for (size_t i = 0; i + pattern.size() <= array.size(); i++)
        if (std::equal(pattern.begin(), pattern.end(), array.begin() + i))
            ret.push_back(i);
    return ret;
}

void Force::loadInput(const std::string &fileName, std::vector<int> &array)
{
    std::ifstream is(fileName.c_str());
    assert(is.good());
    int x;
    while (is >> x)
        array.push_back(x);
}

