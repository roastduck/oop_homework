#include <cassert>
#include <vector>
#include "graph.h"
#include "mst.h"

int main()
{
    std::vector<Graph> res;
    
    res = MST::computeTopKMST(
        Graph(4).
            add_edge(Graph::Edge(0, 1, 1)).
            add_edge(Graph::Edge(1, 2, 2)).
            add_edge(Graph::Edge(2, 3, 4)).
            add_edge(Graph::Edge(3, 1, 3)),
        3);
    assert(res[0].get_tot_weight() == 6);
    assert(res[1].get_tot_weight() == 7);
    assert(res[2].get_tot_weight() == 8);
    
    res = MST::computeTopKMST(
        Graph(5).
            add_edge(Graph::Edge(0, 1, 1)).
            add_edge(Graph::Edge(1, 2, 2)).
            add_edge(Graph::Edge(2, 3, 3)).
            add_edge(Graph::Edge(3, 4, 4)).
            add_edge(Graph::Edge(3, 1, 5)).
            add_edge(Graph::Edge(4, 0, 6)),
        11);
    assert(res[0].get_tot_weight() == 10);
    assert(res[1].get_tot_weight() == 12);
    assert(res[2].get_tot_weight() == 12);
    assert(res[3].get_tot_weight() == 13);
    assert(res[4].get_tot_weight() == 13);
    assert(res[5].get_tot_weight() == 14);
    assert(res[6].get_tot_weight() == 14);
    assert(res[7].get_tot_weight() == 15);
    assert(res[8].get_tot_weight() == 15);
    assert(res[9].get_tot_weight() == 17);
    assert(res[10].get_tot_weight() == 18);

    res = MST::computeTopKMST(
        Graph(4).
            add_edge(Graph::Edge(0, 1, 1)).
            add_edge(Graph::Edge(0, 2, 2)).
            add_edge(Graph::Edge(0, 3, 3)).
            add_edge(Graph::Edge(1, 2, 5)).
            add_edge(Graph::Edge(2, 3, 6)).
            add_edge(Graph::Edge(3, 1, 4)),
        5);
    assert(res[0].get_tot_weight() == 6);
    assert(res[1].get_tot_weight() == 7);
    assert(res[2].get_tot_weight() == 9);
    assert(res[3].get_tot_weight() == 9);
    assert(res[4].get_tot_weight() == 9);
    
    return 0;
}

