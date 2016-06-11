#ifndef TENSCORE_H_INCLUDED
#define TENSCORE_H_INCLUDED
#include <vector>
#include "score.h"

class TenScore : public Score
{
public:
    TenScore(const char* name):Score(name) {}
    void addScore(float x) { scores_.push_back(x); }
    //Assume each score has the same weight
    //in computing the total score
    float computeScore() {
        float sum = 0;
        for (int i = 0; i < (int)scores_.size(); ++i)
            sum += scores_[i];
        sum *= 10.0;
        sum /= (int)scores_.size();
        totalScore_ = sum;
        return sum;
    }
protected:
    std::vector<float> scores_;
    float totalScore_;
};

#endif // TENSCORE_H_INCLUDED
