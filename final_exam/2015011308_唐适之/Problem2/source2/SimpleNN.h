#ifndef SIMPLE_NN_H_
#define SIMPLE_NN_H_

#include <vector>

class SimpleNN
{
public:
    SimpleNN(std::vector<std::vector<float> > &points)
        : _points(points) {}
    
    std::vector<float> search(std::vector<float> &point);

private:
    std::vector<std::vector<float> > _points;
};

#endif // SIMPLE_NN_H

