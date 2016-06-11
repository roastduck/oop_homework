#include <iostream>
#include <algorithm>
#include "BubbleSort.h"

void BubbleSort::sort(std::vector<Student*> &students)
{
    for (int i = 0; i < (int)students.size() - 1; i++)
        for (int j = i + 1; j < (int)students.size(); j++)
            if (students[i]->getAvgScore() > students[j]->getAvgScore())
                std::swap(students[i], students[j]);
    
    std::cout << "Output disabled to make accurate time measurement" << std::endl;
    //for (int i = 0; i < (int)students.size(); ++i)
    //    std::cout << students[i] << std::endl;
}

