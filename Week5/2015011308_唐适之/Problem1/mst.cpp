#include <cmath>
#include <cassert>
#include <set>
#include <queue>
#include <vector>
#include <exception>
#include <algorithm>
#include <functional>
#include "mst.h"
#include "dsu.h"
#include "graph.h"

Graph MST::computeMST(const Graph &g)
{
    DSU mDSU(g.get_size());
    Graph ret(g.get_size());

    std::vector<Graph::Edge> edges(g.get_all_edges());
    std::sort(edges.begin(), edges.end());
    for (const Graph::Edge &e : edges)
        if (! mDSU.isSame(e.x, e.y))
        {
            mDSU.unite(e.x, e.y);
            ret.add_edge(Graph::Edge(e.x, e.y, e.w));
        }

    assert(ret.get_all_edges().size() == ret.get_size()-1);
    return ret;
}

std::vector<Graph> MST::computeTopKMST(const Graph &g, int k)
{
    std::priority_queue
        < Solution, std::vector<Solution>, std::greater<Solution> >
        candidate;
    std::vector<Graph> ret;

    Graph MST = computeMST(g);
    candidate.push(Solution(MST, Graph(MST.get_size()), Graph(MST.get_size())));

    while (ret.size() < k)
    {
        Solution cur = candidate.top();
        candidate.pop();
        if (! cur.counted)
        {
            ret.push_back(cur.tree);
            cur.counted = true;
        }

        try
        {
            std::pair<Solution, Solution> newPair = MST::gen_new_solution(g, cur);
            candidate.push(newPair.first);
            candidate.push(newPair.second);
        } catch (std::exception e)
        {
        }
    }

    return ret;
}

std::pair<MST::Solution, MST::Solution> MST::gen_new_solution(const Graph &g, const Solution &cur)
{
    Graph::Edge add(0, 0, INFINITY), del(0, 0, -INFINITY);
    for (const Graph::Edge &e : g.get_all_edges())
        if (! cur.tree.edge_exists(e.x, e.y) && ! cur.fixOut.edge_exists(e.x, e.y))
        {
            Graph::Edge f = dfs(cur.tree, cur.fixIn, e.x, e.y).first;
            if (! std::isfinite(f.w)) continue;
            if (e.w-f.w < add.w-del.w)
                add = e, del = f;
        }
    if (! std::isfinite(add.w-del.w))
        throw std::exception();
    
    std::pair<MST::Solution, MST::Solution> ret
        (
            MST::Solution(cur.tree, cur.fixIn, cur.fixOut, cur.counted),
            MST::Solution(Graph(g.get_size()), cur.fixIn, cur.fixOut)
        );
    for (const Graph::Edge &te : cur.tree.get_all_edges())
        if (te.x != del.x || te.y != del.y)
            ret.second.tree.add_edge(te);
    ret.second.tree.add_edge(add);
    ret.first.fixIn.add_edge(del);
    ret.second.fixOut.add_edge(del);
    return ret;
}

std::pair<Graph::Edge, bool> MST::dfs(const Graph &tree, const Graph &fixIn, int x, int y, int last)
{
    if (x == y) return std::make_pair(Graph::Edge(0, 0, -INFINITY), true);
    for (const Graph::Edge &e : tree.get_vertex_edges(x))
    {
        int next = (e.x==x ? e.y : e.x);
        if (next == last) continue;
        std::pair<Graph::Edge, bool> got = dfs(tree, fixIn, next, y, x);
        if (! got.second) continue;
        if (fixIn.edge_exists(e.x, e.y))
            return got;
        else
            return std::make_pair(std::max(got.first, e), true);
    }
    return std::make_pair(Graph::Edge(0, 0, -INFINITY), false);
}

