#ifndef INCLUDED_DSU_H
#define INCLUDED_DSU_H

#include<vector>

//! Disjoint Sets Union
class DSU
{
    std::vector<int> father;

    int get(int x)
    {
        return (father[x]==x ? x : get(father[x]));
    }

public:
    DSU(int n)
        : father(n)
    {
        for (int i=0; i<n; i++)
            father[i] = i;
    }

    DSU& unite(int x, int y)
    {
        father[get(x)] = get(y);
        return *this;
    }

    bool isSame(int x, int y)
    {
        return get(x) == get(y);
    }
};

#endif // INCLUDED_DSU_H
