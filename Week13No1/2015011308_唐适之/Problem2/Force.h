#ifndef FORCE_H_
#define FORCE_H_

#include <string>
#include <vector>

/// Brute force
/// Interfaces are the same as those in KMP
class Force
{
public:
    /// initialize with pattern and content array from files
    Force(const std::string &patFileName, const std::string &inputFileName);
    
    /// return all matched positions
    std::vector<int> matchAll();

private:
    /// load from file into array
    void loadInput(const std::string &fileName, std::vector<int> &array);
    
    std::vector<int> array, pattern;
};

#endif // FORCE_H_
