#ifndef ABCDSCORE_H_INCLUDED
#define ABCDSCORE_H_INCLUDED
#include <vector>
#include "score.h"

class ABCDScore : public Score
{
public:
    ABCDScore(const char* name):Score(name) {}
    enum GRADE {A, B, C, D, E};
    //Assume each score has the same weight
    //in computing the total score
    float computeScore() {
        float sum = 0;
        for (int i = 0; i < (int)scores_.size(); ++i)
            sum += (4-(int)scores_[i])/4.0;
        sum *= 100.0;
        sum /= (int)scores_.size();
        totalScore_ = sum;
        return sum;
    }
    void addScore(GRADE x) { scores_.push_back(x); }
protected:
    std::vector<GRADE> scores_;
    float totalScore_;
};

#endif // ABCDSCORE_H_INCLUDED
