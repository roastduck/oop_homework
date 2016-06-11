#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
#include <vector>
#include "score.h"

class Student
{
public:
    Student(int id):id_(id) {}
    // ~Student();
    // BUGFIX
    virtual ~Student(); // this destructor should be virtual
    virtual float computeAvgScore() = 0;
    float getAvgScore() { return avgScore_; }
    void addScore(Score *sc) { scores_.push_back(sc); }
    friend std::ostream & operator << (std::ostream &os, Student *st);
protected:
    int id_;
    std::vector<Score *> scores_;
    float avgScore_;
};

#endif // STUDENT_H_INCLUDED
