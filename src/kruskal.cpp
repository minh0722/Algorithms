#include "kruskal.h"
#include <algorithm>
#include <vector>
#include <stdio.h>

namespace algorithm
{
    DSF::DSF(const DSF&& o)
        : parent(std::move(o.parent)),
          size(std::move(o.size))
    {
    }

    DSF& DSF::operator=(const DSF&& o)
    {
        if(this != &o)
        {
            parent = std::move(o.parent);
            size = std::move(o.size);
        }

        return *this;
    }

    DSF::DSF(int nodeCount)
    {
        parent.resize(nodeCount);
        size.resize(nodeCount);

        for (int i = 0; i < nodeCount; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int DSF::root(int node)
    {
        while (node != parent[node])
        {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }

        return node;
    }

    bool DSF::connected(int from, int to)
    {
        return root(from) == root(to);
    }

    void DSF::connect(int left, int right)
    {
        int leftRoot = root(left);
        int rightRoot = root(right);

        if (size[leftRoot] > size[rightRoot])
        {
            parent[rightRoot] = leftRoot;
            size[leftRoot] += size[rightRoot];
        }
        else
        {
            parent[leftRoot] = rightRoot;
            size[rightRoot] += size[leftRoot];
        }
    }

    DSF kruskal(std::vector<Edge>& graph, size_t nodeCount, int& totalWeight)
    {
        DSF dsf(nodeCount);

        std::sort(graph.begin(), graph.end());

        totalWeight = 0;
        for (size_t i = 0; i < graph.size(); ++i)
        {
            if (!dsf.connected(graph[i].from, graph[i].to))
            {
                dsf.connect(graph[i].from, graph[i].to);
                totalWeight += graph[i].weight;
            }
        }

        return dsf;
    }
}

// int main()
// {
//
//     int nodeCount, edgeCount;
//     scanf("%d %d", &nodeCount, &edgeCount);
//
//     std::vector<Edge> graph(edgeCount);
//     DSF dsf(nodeCount);
//
//     for (int i = 0; i < edgeCount; ++i)
//     {
//         scanf("%d %d %d", &graph[i].from, &graph[i].to, &graph[i].weight);
//     }
//
//     std::sort(graph.begin(), graph.end());
//
//     int totalWeight = 0;
//     for (int i = 0; i < edgeCount; ++i)
//     {
//         if (!dsf.connected(graph[i].from, graph[i].to))
//         {
//             dsf.connect(graph[i].from, graph[i].to);
//             totalWeight += graph[i].weight;
//         }
//     }
//
//     printf("Total minimum weight is %d\n", totalWeight);
//
//     return 0;
// }






