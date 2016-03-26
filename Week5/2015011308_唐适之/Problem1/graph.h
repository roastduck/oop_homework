#ifndef INCLUDED_GRAPH_H
#define INCLUDED_GRAPH_H

#include <vector>

//! An undirected graph
class Graph
{
public:
    //! Construct a graph with size n
    Graph(int n);

    //! An edge between `x` and `y` with weight `w`
    struct Edge
    {
        int x, y;
        double w;
        Edge(int _x, int _y, double _w)
            : x(_x), y(_y), w(_w) {}
    };

    //! Add an edge to the graph
    Graph& add_edge(const Edge &e);

    //! Get all edges in the graph
    const std::vector<Edge>& get_all_edges() const;

    //! Get edges connected to one vertex
    const std::vector<Edge>& get_vertex_edges(int v) const;

    //! If edge exists
    bool edge_exists(int x, int y) const;

    //! Get total weight
    double get_tot_weight() const;

    //! Get graph size
    int get_size() const;

    //! Output the graph
    void output() const;

private:
    double totWeight;
    std::vector<Edge> allEdges;
    std::vector< std::vector<Edge> > vertexEdges;
    std::vector< std::vector<bool> > adjacentMatrix;
};

inline bool operator<(const Graph::Edge &a, const Graph::Edge &b)
{
    return a.w < b.w;
}

inline bool operator>(const Graph::Edge &a, const Graph::Edge &b)
{
    return a.w > b.w;
}

inline bool operator<(const Graph &a, const Graph &b)
{
    return a.get_tot_weight() < b.get_tot_weight();
}

inline bool operator>(const Graph &a, const Graph &b)
{
    return a.get_tot_weight() > b.get_tot_weight();
}

#endif // INCLUDED_GRAPH_H
