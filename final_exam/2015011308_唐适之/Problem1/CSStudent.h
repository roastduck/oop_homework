#ifndef CSSTUDENT_H_INCLUDED
#define CSSTUDENT_H_INCLUDED
#include "student.h"

class CSStudent : public Student {
public:
    CSStudent(int id):Student(id) {}
    ~CSStudent() {}
    int getOOPScore() { return OOPScore_; }
    void setOOPScore(float sc) { OOPScore_ = sc; }
    float computeAvgScore() {
        avgScore_ = 0;
        for (int i = 0; i < (int)scores_.size(); ++i)
        {
            avgScore_ += scores_[i]->computeScore();
        }
        avgScore_ /= (int)scores_.size();
        //more weight for OOP score
        avgScore_ = avgScore_*0.3+OOPScore_*0.7;
        //rounding to two-decimal number
        avgScore_ = ((int)(avgScore_*100+0.5))/100.0;
        return avgScore_;
    }
private:
    int OOPScore_;
};

#endif // CSSTUDENT_H_INCLUDED
