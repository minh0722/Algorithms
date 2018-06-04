#ifndef ALGORITHM_KRUSKAL
#define ALGORITHM_KRUSKAL

/*
 * This algorithm find the minimum spanning tree using disjoint set forest.
 * The disjoint set forest contains an array of parent of every node and
 * an array containing how many children each node has (including itself)
 * The graph has to be in the form of array of edges <from, to, weight>
 * and it must be sorted before the algorithm can be executed
 *
*/

#include <vector>
#include <cstddef>
#include "graph_edge.h"

namespace algorithm
{
    struct DSF
    {
        std::vector<int> parent;
        std::vector<int> size;

        DSF(const DSF&& o);
        DSF& operator=(const DSF&& o);
        DSF(int nodeCount);

        int root(int node);
        bool connected(int from, int to);
        void connect(int left, int right);
    };

    DSF kruskal(std::vector<Edge>& graph, size_t nodeCount, int& totalWeight);
}

#endif // ALGORITHM_KRUSKAL