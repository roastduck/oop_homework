#include <cassert>
#include "SimpleNN.h"

static float dis2(const std::vector<float> &x, const std::vector<float> &y)
{
    float ret(0);
    assert(x.size() == y.size());
    for (int i = 0; i < (int)x.size(); i++)
        ret += (x[i] - y[i]) * (x[i] - y[i]);
    return ret;
}

std::vector<float> SimpleNN::search(std::vector<float> &point)
{
    assert(_points.size() > 0);
    auto ret = _points.front();
    float retDis = dis2(ret, point);
    for (int i = 2; i < (int)_points.size(); i++)
    {
        float tmpDis = dis2(_points[i], point);
        if (tmpDis < retDis)
            retDis = tmpDis, ret = _points[i];
    }
    return ret;
}

