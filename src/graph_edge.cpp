#include "graph_edge.h"

namespace algorithm
{
    bool Edge::operator<(const Edge& e) const
    {
        return weight < e.weight;
    }
}