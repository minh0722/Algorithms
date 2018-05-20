#include "graph_node.h"

namespace Algorithm
{
	Node::Node(int f, int t, int w)
		: from(f), to(t), weight(w) {}

	bool Node::operator<(const Node& n) const
	{
		return weight > n.weight;
	}
}