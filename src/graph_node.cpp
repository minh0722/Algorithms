#include "graph_node.h"

namespace algorithm
{
	Node::Node(int f, int t, int w)
		: from(f), to(t), weight(w) {}

	bool Node::operator<(const Node& n) const
	{
		return weight > n.weight;
	}

    Nodev2::Nodev2(int n, int w) 
        : num(n), weight(w) 
    {
    }

    bool Nodev2::operator<(const Nodev2& n) const
    {
        return weight < n.weight;
    }
}