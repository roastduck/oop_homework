#include <cassert>
#include "BaseNN.h"
#include "KDTree.h"
using namespace std;

//NOTE: here is definition of the constructor of BaseNearestNeighbor
BaseNearestNeighbor::BaseNearestNeighbor(std::vector<std::vector<int> > &points)
{
    //NOTE: add the points into the k-d tree one-by-one
    for (auto &item : points)
    {
        bool res = tree_.add(item);
        assert(res == true);
    }
}

void BaseNearestNeighbor::search(std::vector<int> &pnt)
{
    //NOTE: Call KDTree's findNearest() interface for finding the nearest multidimentional point to the given point pnt
    //Please fill in the code here
    qPoint_ = pnt;
    std::vector<KDNode*> visitedNode;
    KDNode *nearestNode = tree_.findNearest(pnt, visitedNode);
    getNN(nearestNode->x_);
    for (KDNode *item : visitedNode)
        getVisitedPoint(item->x_);
}

