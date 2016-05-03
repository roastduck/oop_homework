//////////////////////////////////////////////////////////////////////////
// Description: this is the base implementation of a simple maze router
// Author: YHL
// Date: 20120323
// Note: Modify this file and add OptRouter.cpp file for the
//       implementation of the additional functionalities
//////////////////////////////////////////////////////////////////////////
#ifndef OPT_ROUTER_H_
#define OPT_ROUTER_H_

#include <cassert>
#include "BaseRouter.h"

class OptRouter:public BaseRouter
{
    // 2D vector / point
    struct IPoint
    {
        int m_x, m_y;
        OptRouter *m_p;
    public:
        IPoint(int _x, int _y, OptRouter *_p) : m_x(_x), m_y(_y), m_p(_p) {}
        IPoint(int index, OptRouter *_p): m_p(_p) { m_p->compXYIndex(index, m_x, m_y); }
        int getIndex() const { return m_p->compIndex(m_x, m_y); }
        bool inRange() const { return m_y >= 0 && m_y < m_p->m_row && m_x < m_p->m_col && m_x >= 0; }
    };
    
    friend IPoint;
    
    friend IPoint operator+(const IPoint &A, const IPoint &B)
    {
        assert(A.m_p == B.m_p);
        return IPoint(A.m_x + B.m_x, A.m_y + B.m_y, A.m_p);
    }
    friend IPoint operator-(const IPoint &A, const IPoint &B)
    {
        assert(A.m_p == B.m_p);
        return IPoint(A.m_x - B.m_x, A.m_y - B.m_y, A.m_p);
    }
    
    const IPoint m_dir[4] = { IPoint(-1, 0, this), IPoint(0, 1, this), IPoint(1, 0, this), IPoint(0, -1, this) };
    const char m_dir_name[4][7] = { "left", "up", "right", "down" };
    
public:
    OptRouter(int r, int c, const Point &source, const Point &target, const PointVector &obs)
        : BaseRouter(r, c, source, target, obs)
    {
    }
    ~OptRouter() {}
    
    // override
    // use BFS with time O(n^2)
    void mazeBacktrace();
    
    //override
    bool route();
};

#endif
