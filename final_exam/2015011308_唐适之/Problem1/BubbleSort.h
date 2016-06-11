#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include "Sorter.h"

class BubbleSort : public Sorter
{
public:
    void sort(std::vector<Student*> &students) override;
};

#endif // BUBBLE_SORT_H_

