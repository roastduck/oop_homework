#ifndef BASE_NN_
#define BASE_NN_
#include <vector>
#include "KDTree.h"

class BaseNearestNeighbor 
{
public:
    BaseNearestNeighbor(std::vector<std::vector<float> > &points);
    void search(std::vector<float> &point);
protected:
    virtual void getNN(std::vector<float> &point) = 0;
    virtual void getVisitedPoint(std::vector<float> &point) = 0;
    std::vector<float> qPoint_; //store the query point from input
private:
    KDTree<float> tree_;
};

#endif

