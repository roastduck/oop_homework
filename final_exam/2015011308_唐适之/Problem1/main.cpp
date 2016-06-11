#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "CSStudent.h"
#include "ABCDScore.h"
#include "TenScore.h"
#include "RadixSort.h"
#include "BubbleSort.h"
#include "Timer.h"

using namespace std;

int main()
{
    std::cout << "Running" << std::endl;
    std::cout << "Output disabled to make accurate time measurement" << std::endl;
    
    //do not use srand to obtain same results for each run
    //srand((unsigned)time(NULL));
    //sort students by OOP score using Radix sort
    vector<Student *> students;
    for (int i = 0; i < 10000; ++i)
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
    // radixSortStudents(students);
    Sorter *sorter = NULL;
    Timer *timerR = new Timer(), *timerB = new Timer();
    auto bak = students;
    
    std::cout << " ============ Radix Sort ==============" << std::endl;
    sorter = new RadixSort();
    timerR->run(sorter, students);
    delete sorter;
    sorter = NULL;
    
    students = bak;
    bak.clear();
    
    std::cout << std::endl;
    std::cout << " ============ Bubble Sort =============" << std::endl;
    sorter = new BubbleSort();
    timerB->run(sorter, students);
    delete sorter;
    sorter = NULL;
    
    std::cout << std::endl;
    std::cout << "Radix Sort time = " << timerR->getResult() << "(s)" << std::endl;
    std::cout << "Bubble Sort time = " << timerB->getResult() << "(s)" << std::endl;
    
    delete timerR;
    delete timerB;
    
    //here is the code for using the sorted vector students
    //e.g., printing the students' names in the sorted order

    for (int i = 0; i < (int)students.size(); ++i)
        delete students[i];

    return 0;
}
