#ifndef INCLUDED_MST_H
#define INCLUDED_MST_H

#include <cmath>
#include <vector>
#include "graph.h"

class MST
{
public:
    //! Generate MST
    /**
     * O(n^2 log n) Kruskal's Algorithm
     */
    static Graph computeMST(const Graph &g);

    //! Generate top-k MST
    /**
     * O(k n^3) algorithm, referring to 余鼎力 寻找第k优解的几种方法 2014
     */
    static std::vector<Graph> computeTopKMST(const Graph &g, int k);

private:
    struct Solution
    {
        Graph tree,
              fixIn /*edges that stay in the tree*/,
              fixOut /*edges that stay out of the tree*/;
        bool counted; // counted in answer

        Solution(const Graph &_tree, const Graph &_fixIn, const Graph &_fixOut, bool _counted = false)
            : tree(_tree), fixIn(_fixIn), fixOut(_fixOut), counted(_counted) {}
    };

    inline friend bool operator<(const MST::Solution &a, const MST::Solution &b)
    {
        return a.tree < b.tree;
    }

    inline friend bool operator>(const MST::Solution &a, const MST::Solution &b)
    {
        return a.tree > b.tree;
    }

    //! Generate larger tree
    /**
     * throws std::exception
     */
    static std::pair<Solution,Solution> gen_new_solution(const Graph &g, const Solution &cur);

    //! search the minimal edge from x to y in g
    /**
     * second = true means found
     */
    static std::pair<Graph::Edge, bool> dfs(const Graph &tree, const Graph &fixIn, int x, int y, int last=-1);
};

#endif // INCLUDED_MST_H
