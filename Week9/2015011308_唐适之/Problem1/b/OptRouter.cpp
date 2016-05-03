#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <unordered_map>
#include "OptRouter.h"
// Used namespace in `BaseRouter.h` which cannot be modified
// Don't blame me...

struct Journey
{
    int turn[4], lastDir[4], lastPos[4];
    // number of turns, last direction, last position in 4 directions
    bool inList[4];
    
    Journey()
    {
        memset(turn, 127, sizeof turn);
        memset(inList, 0, sizeof inList);
    }
    
    int minDir() const
    {
        int m(0x7f7f7f7f); // consistent with memset 127
        for (int k=0; k<4; k++)
            m = min(m, turn[k]);
        for (int k=0; k<4; k++)
            if (turn[k] == m) return k;
        assert(false);
    }
};

// override
void OptRouter::mazeBacktrace()
{
    static list< pair<IPoint, int> > bfsList; // position + direction
    static unordered_map<int, Journey> journey;
    bfsList.push_back(make_pair(IPoint(m_targetIndex, this), 0));
    bfsList.push_back(make_pair(IPoint(m_targetIndex, this), 1));
    bfsList.push_back(make_pair(IPoint(m_targetIndex, this), 2));
    bfsList.push_back(make_pair(IPoint(m_targetIndex, this), 3));
    memset(journey[m_targetIndex].turn, 0, sizeof(journey[m_targetIndex].turn));
    memset(journey[m_targetIndex].inList, 0, sizeof(journey[m_targetIndex].inList));
    
    while (! journey.count(m_sourceIndex))
    {
        assert(! bfsList.empty());
        const IPoint pos(bfsList.front().first);
        const int posi(pos.getIndex());
        int dir(bfsList.front().second);
        bfsList.pop_front();
        const IPoint next(pos + m_dir[dir]);
        const int nexti(next.getIndex());
        if (next.inRange() && m_grids[posi] == m_grids[nexti] + 1)
            if (journey[posi].turn[dir] < journey[nexti].turn[dir])
            {
                journey[nexti].turn[dir] = journey[posi].turn[dir];
                journey[nexti].lastDir[dir] = dir;
                journey[nexti].lastPos[dir] = posi;
                if (! journey[nexti].inList[dir])
                {
                    journey[nexti].inList[dir] = true;
                    bfsList.push_front(make_pair(next, dir));
                    // enlist from the front because the weight is 0
                    printf(
                           "BackTrace grid [%d,%d] cost %d\n direction %s\n",
                           next.m_x, next.m_y, m_grids[nexti], m_dir_name[journey[nexti].turn[dir]]
                          );
                    // wyl said I should print this
                }
            }
        for (int k=0; k<4; k++)
            if (journey[posi].turn[dir] + 1 < journey[posi].turn[k])
            {
                journey[posi].turn[k] = journey[posi].turn[dir] + 1;
                journey[posi].lastDir[k] = dir;
                journey[posi].lastPos[k] = posi;
                if (! journey[posi].inList[k])
                {
                    journey[posi].inList[k] = true;
                    bfsList.push_back(make_pair(pos, k));
                    printf(
                           "BackTrace grid [%d,%d] cost %d\n direction %s\n",
                           pos.m_x, pos.m_y, m_grids[posi], m_dir_name[journey[posi].turn[k]]
                          );
                    // wyl said I should print this
                }
            }
        journey[posi].inList[dir] = false;
    }
    
    int pos = m_sourceIndex, dir = journey[pos].minDir();
    printf("Minimal turns: %d\n", journey[pos].turn[dir]);
    while (true)
    {
		if (m_path.empty() || m_path.back() != pos)
            m_path.push_back(pos);
        if (pos == m_targetIndex) break;
        int _dir = journey[pos].lastDir[dir];
        int _pos = journey[pos].lastPos[dir];
        pos = _pos, dir = _dir;
    }
    reverse(m_path.begin(), m_path.end());
    
    printf("Found path: ");
    for (unsigned i = 0; i < this->m_path.size(); ++ i)
    {
        int index = this->m_path[i];
        int x, y;
        this->compXYIndex(index, x, y);
        printf("[%d,%d] ", x, y);
    }
    putchar('\n');
}

// maze routing
// not modified
// `mazeBacktrace` is not virtual so I have to paste `route`
bool OptRouter::route(void)
{
    if (this->m_sourceIndex < 0 || this->m_targetIndex < 0 || this->m_row <= 0 || this->m_col <= 0)
        return false;

    this->m_path.clear();

    //initialize the cost of the source grid
    m_grids[this->m_sourceIndex] = 0;

    //maze expansion
    if (mazeSearch())
    {
        mazeBacktrace();
        return true;
    }
    else
        return false;
}
