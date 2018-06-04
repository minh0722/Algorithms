#ifndef ALGORITHM_GRAPH_EDGE
#define ALGORITHM_GRAPH_EDGE

namespace algorithm
{
    struct Edge
    {
        int from = 0;
        int to = 0;
        int weight = 0;

        bool operator<(const Edge& e) const;
    };
}
#endif // ALGORITHM_GRAPH_EDGE