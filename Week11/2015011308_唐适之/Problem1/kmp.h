#ifndef KMP_H_
#define KMP_H_

#include "patternmatch.h"

/**
 * The KMP Algorithm
 */
class KMP : public PatternMatch
{
public:
    void addPattern(const std::string &_p) override;
    void match(const std::string &s) override;
    std::vector< std::pair<std::string, int> > getResult() override;

private:
    struct pattern_t
    {
        std::string p; // pattern
        int cnt; // matched time
        std::vector<int> bw; // backward array
    };

    std::vector<pattern_t> patterns;
};

#endif // KMP_H_

