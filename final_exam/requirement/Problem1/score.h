#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include <cstring>
#include <cstdlib>

class Score
{
public:
    Score(const char* name) {
        subjectName_ = new char[strlen(name)+1];
        strcpy(subjectName_, name);
    }
    virtual float computeScore() = 0;
protected:
    char* subjectName_;
};


#endif // SCORE_H_INCLUDED
