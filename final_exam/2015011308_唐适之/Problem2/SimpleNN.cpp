#include <cassert>
#include "SimpleNN.h"

static int dis2(const std::vector<int> &x, const std::vector<int> &y)
{
    int ret(0);
    assert(x.size() == y.size());
    for (int i = 0; i < (int)x.size(); i++)
        ret += (x[i] - y[i]) * (x[i] - y[i]);
    return ret;
}

std::vector<int> SimpleNN::search(std::vector<int> &point)
{
    assert(_points.size() > 0);
    auto ret = _points.front();
    int retDis = dis2(ret, point);
    for (int i = 2; i < (int)_points.size(); i++)
    {
        int tmpDis = dis2(_points[i], point);
        if (tmpDis < retDis)
            retDis = tmpDis, ret = _points[i];
    }
    return ret;
}

