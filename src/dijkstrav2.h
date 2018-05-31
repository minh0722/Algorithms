#ifndef ALGORITHM_DIJKSTRA_V2
#define ALGORITHM_DIJKSTRA_V2

#include <vector>
#include "graph_node.h"
#include "common.h"

namespace algorithm
{
    namespace graph
    {
        ALGO_API void dijkstrav2(const std::vector<std::vector<Nodev2> >& graph, int* distance, int from);
    }
}

#endif // ALGORITHM_DIJKSTRA_V2