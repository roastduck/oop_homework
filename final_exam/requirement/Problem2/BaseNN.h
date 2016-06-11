#ifndef BASE_NN_
#define BASE_NN_
#include <vector>
#include "KDTree.h"

class BaseNearestNeighbor 
{
public:
    BaseNearestNeighbor(std::vector<std::vector<int> > &points);
    void search(std::vector<int> &point);
protected:
    virtual void getNN(std::vector<int> &point) = 0;
    virtual void getVisitedPoint(std::vector<int> &point) = 0;
    std::vector<int> qPoint_; //store the query point from input
private:
    KDTree tree_;
};

#endif

