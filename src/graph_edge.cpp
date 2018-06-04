#include "graph_edge.h"

bool Edge::operator<(const Edge& e) const
{
    return weight < e.weight;
}