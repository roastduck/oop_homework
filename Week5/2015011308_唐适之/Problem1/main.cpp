#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "graph.h"
#include "mst.h"

const int n = 20, lim = 10001, topk = 5;

inline double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    srand(time(0));

    std::cout << "Points:" << std::endl;
    int X[n], Y[n];
    for (int i=0; i<n; i++)
    {
        bool ok(true);
        do
        {
            X[i] = rand() % lim;
            Y[i] = rand() % lim;
            for (int j=0; j<i; j++)
                if (X[j]==X[i] && Y[j]==Y[i])
                {
                    ok = false;
                    break;
                }
        } while (!ok);
        std::cout << " " << i << ": (" << X[i] << ", " << Y[i] << ")" << std::endl;
    }
    std::cout << "=====================" << std::endl << std::endl;

    Graph g(n);
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            g.add_edge(Graph::Edge(i, j, dist(X[i], Y[i], X[j], Y[j])));

    std::cout << "MST:" << std::endl;
    MST::computeMST(g).output();
    std::cout << "=====================" << std::endl << std::endl;

    std::cout << "Top " << topk << " MST:" << std::endl;
    std::cout << "---------------------" << std::endl << std::endl;
    for (const Graph &t: MST::computeTopKMST(g, topk))
    {
        static int cnt(0);
        std::cout << "number " << ++cnt << ":" << std::endl;
        t.output();
        std::cout << "---------------------" << std::endl << std::endl;
    }
    return 0;
}

