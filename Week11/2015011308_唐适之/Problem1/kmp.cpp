#include "kmp.h"

void KMP::addPattern(const std::string &_p)
{
    patterns.push_back(pattern_t());
    patterns.back().p = _p;
    patterns.back().cnt = 0;
    std::vector<int> &bw = patterns.back().bw;
    bw.resize(_p.length(), -1);

    for (int i = 1, j = -1; i < (int)_p.length(); i++)
    {
        while (j >= 0 && _p[j + 1] != _p[i]) j = bw[j];
        if (_p[j + 1] == _p[i]) j++;
        bw[i] = j;
        if (j + 1 == (int)_p.length()) j = bw[j];
    }
}

void KMP::match(const std::string &s)
{
    for (auto &item : patterns)
    {
        const std::string &p = item.p;
        int &cnt = item.cnt;
        std::vector<int> &bw = item.bw;

        cnt = 0;
        for (int i = 0, j = -1; i < (int)s.length(); i++)
        {
            while (j >= 0 && p[j + 1] != s[i]) j = bw[j];
            if (p[j + 1] == s[i]) j++;
            if (j + 1 == (int)p.length())
            {
                cnt++;
                j = bw[j];
            }
        }
    }
}

std::vector< std::pair<std::string, int> > KMP::getResult()
{
    std::vector< std::pair<std::string, int> > ret;
    ret.reserve(patterns.size());
    for (const auto &item : patterns)
        ret.push_back(std::make_pair(item.p, item.cnt));
    return ret;
}

