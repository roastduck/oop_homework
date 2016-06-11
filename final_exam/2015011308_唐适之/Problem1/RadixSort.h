#ifndef RADIX_SORT_H_
#define RADIX_SORT_H_

#include "Sorter.h"

class RadixSort : public Sorter
{
public:
    void sort(std::vector<Student*> &students) override;
};

#endif // RADIX_SORT_H_

