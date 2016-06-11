#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "CSStudent.h"
#include "ABCDScore.h"
#include "TenScore.h"

using namespace std;

//radix sort for students according to avg score
void radixSortStudents(vector<Student *> students)
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
    for (int i = 0; i < (int)students.size(); ++i)
        cout << students[i] << endl;
}

int main()
{
    //do not use srand to obtain same results for each run
    //srand((unsigned)time(NULL));
    //sort students by OOP score using Radix sort
    vector<Student *> students;
    for (int i = 0; i < 30; ++i)
    {
        CSStudent *st = new CSStudent(i);
        ABCDScore *sc1 = new ABCDScore("Physics");
        sc1->addScore((ABCDScore::GRADE)(rand()%5));
        sc1->addScore((ABCDScore::GRADE)(rand()%5));
        sc1->addScore((ABCDScore::GRADE)(rand()%5));
        TenScore *sc2 = new TenScore("Math");
        sc2->addScore(rand()%10);
        sc2->addScore(rand()%10);
        sc2->addScore(rand()%10);
        st->addScore(sc1);
        st->addScore(sc2);
        st->setOOPScore(rand()%101);
        st->computeAvgScore();
        students.push_back(st);
    }
    //sort the students according to average score for future use
    radixSortStudents(students);
    
    //here is the code for using the sorted vector students
    //e.g., printing the students' names in the sorted order

    for (int i = 0; i < (int)students.size(); ++i)
        delete students[i];

    return 0;
}
