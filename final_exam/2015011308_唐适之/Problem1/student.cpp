#include "student.h"
using namespace std;

// standard stream operator overloading
ostream & operator << (ostream &os, Student *st)
{
    cout << "Student " << st->id_ << " avg score " << st->avgScore_;
    return cout;
}

// destructor
Student::~Student()
{
    for (int i = 0; i < (int)scores_.size(); ++i)
        delete scores_[i];
    scores_.clear();
}
