#ifndef PATTERNMATCH_H_
#define PATTERNMATCH_H_

#include <string>
#include <vector>
#include <utility>

/**
 * This class provides an interface to perform
 * multiple patterns match
 */
class PatternMatch
{
public:
    virtual ~PatternMatch() {}

    /// Add a pattern to match
    virtual void addPattern(const std::string &_p) = 0;

    /// Match s with the added patterns
    virtual void match(const std::string &s) = 0;

    /// How many times did each patterns occur in
    /// previous match?
    /// @return : vector of (pattern, count) pair
    virtual std::vector< std::pair<std::string, int> > getResult() = 0;
};

#endif // PATTERN_MATCH_

