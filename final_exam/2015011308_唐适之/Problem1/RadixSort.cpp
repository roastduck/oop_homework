#include <cassert>
#include <iostream>
#include "RadixSort.h"

using namespace std;

//radix sort for students according to avg score
// BUGFIX
void RadixSort::sort(vector<Student *> &students) // should pass by reference
{
    vector<Student *> bak((int)students.size(), (Student *)NULL);
    assert((int)students.size() > 0);
    float maxScore = students[0]->getAvgScore();
    //Get the greatest score
    for (int i = 1; i < (int)students.size(); i++)
    {
        if (students[i]->getAvgScore() > maxScore)
        maxScore = students[i]->getAvgScore();
    }
    const int BASE = 10;
    int exp = 1;
    while ((int)(maxScore*100) / exp > 0)
    {
        int bucket[BASE] = { 0 };
        for (int i = 0; i < (int)students.size(); ++i)
            bucket[((int)(students[i]->getAvgScore()*100) / exp) % BASE]++;
        for (int i = 1; i < BASE; i++)
            bucket[i] += bucket[i - 1]; //similar to count sort algorithm i.e. c[i]=c[i]+c[i-1];
        for (int i = (int)students.size() - 1; i >= 0; i--)
            bak[--bucket[((int)(students[i]->getAvgScore()*100) / exp) % BASE]] = students[i];
        //Copy back
        for (int i = 0; i < (int)students.size(); ++i)
            students[i] = bak[i];
        exp *= BASE;
    }
    std::cout << "Output disabled to make accurate time measurement" << std::endl;
    //for (int i = 0; i < (int)students.size(); ++i)
    //    cout << students[i] << endl;
}

