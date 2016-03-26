#include <cassert>
#include <iostream>
#include "graph.h"

Graph::Graph(int n)
    : totWeight(0), vertexEdges(n),
      adjacentMatrix(n, std::vector<bool>(n, false)) {}

Graph& Graph::add_edge(const Graph::Edge &e)
{
    assert(e.x != e.y);
    assert(e.x>=0 && e.x<get_size() && e.y>=0 && e.y<get_size());
    assert(! adjacentMatrix[e.x][e.y]);

    allEdges.push_back(e);
    vertexEdges[e.x].push_back(e);
    vertexEdges[e.y].push_back(e);
    adjacentMatrix[e.x][e.y] = adjacentMatrix[e.y][e.x] = true;
    totWeight += e.w;
    return *this;
}

const std::vector<Graph::Edge>& Graph::get_all_edges() const
{
    return allEdges;
}

const std::vector<Graph::Edge>& Graph::get_vertex_edges(int v) const
{
    return vertexEdges[v];
}

bool Graph::edge_exists(int x, int y) const
{
    return adjacentMatrix[x][y];
}

double Graph::get_tot_weight() const
{
    return totWeight;
}

int Graph::get_size() const
{
    return vertexEdges.size();
}

void Graph::output() const
{
    std::cout << "Edges:" << std::endl;
    for (const Graph::Edge &e : allEdges)
        std::cout << " " << e.x << " -- " << e.y << " : " << e.w << std::endl;
    std::cout << "Total Weight:" << std::endl;
    std::cout << " " << totWeight << std::endl;
}

