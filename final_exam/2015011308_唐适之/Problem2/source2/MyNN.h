#ifndef MY_NN_
#define MY_NN_
#include <ostream>
#include "BaseNN.h"
    
//NOTE: need to add the overloaded stream operator << for MyNN

class MyNN : public BaseNearestNeighbor
{
public:
    //NOTE: add the constructor for MyNN here
    MyNN(std::vector<std::vector<float> > &points)
        : BaseNearestNeighbor(points) {}
protected:
    void getNN(std::vector<float> &point)
    {
        nnPoint_ = point;
    }
    
    void getVisitedPoint(std::vector<float> &point)
    {
        visitedPoints_.push_back(point);
    }
    
private:
    friend std::ostream &operator<<(std::ostream &os, const MyNN &item);
    
    std::vector<float> nnPoint_;
    std::vector<std::vector<float> > visitedPoints_;
};

#endif

