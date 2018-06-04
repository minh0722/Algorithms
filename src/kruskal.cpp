#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include "graph_edge.h"

/*
 * This algorithm find the minimum spanning tree using disjoint set forest.
 * The disjoint set forest contains an array of parent of every node and
 * an array containing how many children each node has (including itself)
 * The graph has to be in the form of array of edges <from, to, weight>
 * and it must be sorted before the algorithm can be executed
 *
*/

struct DSF
{
    std::vector<int> parent;
    std::vector<int> size;

    DSF(int nodeCount)
    {
        parent.resize(nodeCount);
        size.resize(nodeCount);

        for (int i = 0; i < nodeCount; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int root(int node)
    {
        while (node != parent[node])
        {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        
        return node;
    }

    bool connected(int from, int to)
    {
        return root(from) == root(to);
    }

    void connect(int left, int right)
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
};

int main()
{

    int nodeCount, edgeCount;
    scanf("%d %d", &nodeCount, &edgeCount);

    std::vector<Edge> graph(edgeCount);
    DSF dsf(nodeCount);

    for (int i = 0; i < edgeCount; ++i)
    {
        scanf("%d %d %d", &graph[i].from, &graph[i].to, &graph[i].weight);
    }

    std::sort(graph.begin(), graph.end());

    int totalWeight = 0;
    for (int i = 0; i < edgeCount; ++i)
    {
        if (!dsf.connected(graph[i].from, graph[i].to))
        {
            dsf.connect(graph[i].from, graph[i].to);
            totalWeight += graph[i].weight;
        }
    }

    printf("Total minimum weight is %d\n", totalWeight);

    return 0;
}






