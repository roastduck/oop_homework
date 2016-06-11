#ifndef MY_NN_
#define MY_NN_
#include <ostream>
#include "BaseNN.h"
    
//NOTE: need to add the overloaded stream operator << for MyNN

class MyNN : public BaseNearestNeighbor
{
public:
    //NOTE: add the constructor for MyNN here
protected:
    void getNN(std::vector<int> &point);
    void getVisitedPoint(std::vector<int> &point);
private:
    std::vector<int> nnPoint_;
    std::vector<std::vector<int> > visitedPoints_;
};

#endif

