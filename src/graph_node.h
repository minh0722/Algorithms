#ifndef ALGORITHM_GRAPH_NODE
#define ALGORITHM_GRAPH_NODE

namespace Algorithm
{
	struct Node
	{
		int from = 0;
		int to = 0;
		int weight = 0;

		Node(int f, int t, int w);
		bool operator<(const Node& n) const;
	};
}

#endif