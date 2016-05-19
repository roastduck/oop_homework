#ifndef RK_H_
#define RK_H_

#include "patternmatch.h"

/**
 * Rabin-Karp Algorithm
 */
class RK : public PatternMatch
{
public:
    void addPattern(const std::string &_p) override;
    void match(const std::string &s) override;
    std::vector< std::pair<std::string, int> > getResult() override;

private:
    /// What's the next hash value after adding a character in the end?
    int nextHash(int cur, char c);

    /// Hash value of a segment i..j
    /// @param1 hash1 : hash value of 1..i-1
    /// @param2 hash2 : hash value of 1..j
    /// @param3 length : j-i+1
    int segHash(int hash1, int hash2, int length);
    
    /// Calculate factor1^(0..n)
    void calcPow(int n);

    struct pattern_t
    {
        std::string p; // pattern
        int cnt /* matched time */, hash;
    };

    const int factor1 = 17389, factor2 = 27449, factor3 = 32749;

    std::vector<int> pow;
    std::vector<pattern_t> patterns;
};

#endif // RK_H_
