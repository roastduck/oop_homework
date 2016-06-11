#ifndef SORTER_H_
#define SORTER_H_

#include <vector>
#include "Student.h"

/// Sort students
class Sorter
{
public:
    virtual ~Sorter() {}
    virtual void sort(std::vector<Student*> &students) = 0;
};

#endif // SORTER_H_

