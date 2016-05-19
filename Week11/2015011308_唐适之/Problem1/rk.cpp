#include <algorithm>
#include "rk.h"

void RK::addPattern(const std::string &_p)
{
    patterns.push_back(pattern_t());
    patterns.back().p = _p;
    patterns.back().cnt = 0;
    for (char c : _p)
        patterns.back().hash = nextHash(patterns.back().hash, c);
}

void RK::match(const std::string &s)
{
    size_t maxLen(0);
    for (const auto &item : patterns)
        maxLen = std::max(maxLen, item.p.length());
    calcPow(maxLen);

    for (auto &item : patterns)
        item.cnt = 0;

    std::vector<int> hash; // current hash value of s's prefix
    hash.reserve(s.length());
    for (size_t i = 0; i < s.length(); i++)
    {
        hash.push_back(nextHash(i ? hash[i - 1] : 0, s[i]));
        for (auto &item : patterns)
        {
            const std::string &p = item.p;
            int &cnt = item.cnt, hashP = item.hash;
            if (i >= p.length() - 1 && segHash(i == p.length() - 1 ? 0 : hash[i - p.length()], hash[i], p.length()) == hashP)
                if (! s.compare(i - p.length() + 1, p.length(), p))
                    cnt++;
        }
    }
}

std::vector< std::pair<std::string, int> > RK::getResult()
{
    std::vector< std::pair<std::string, int> > ret;
    ret.reserve(patterns.size());
    for (const auto &item : patterns)
        ret.push_back(std::make_pair(item.p, item.cnt));
    return ret;
}

int RK::nextHash(int cur, char c)
{
    return (cur * factor1 + c * factor2) % factor3;
}

int RK::segHash(int hash1, int hash2, int length)
{
    return (((hash2 - hash1 * pow[length]) % factor3) + factor3) % factor3;
}

void RK::calcPow(int n)
{
    pow.clear();
    pow.reserve(n + 1);
    pow.push_back(1);
    for (int i = 0; i < n; i++)
        pow.push_back((pow.back() * factor1) % factor3);
}

