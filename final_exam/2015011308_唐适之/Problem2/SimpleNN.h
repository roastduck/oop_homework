#ifndef SIMPLE_NN_H_
#define SIMPLE_NN_H_

#include <vector>

class SimpleNN
{
public:
    SimpleNN(std::vector<std::vector<int> > &points)
        : _points(points) {}
    
    std::vector<int> search(std::vector<int> &point);

private:
    std::vector<std::vector<int> > _points;
};

#endif // SIMPLE_NN_H

