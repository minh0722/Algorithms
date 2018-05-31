#ifndef ALGORITHM_DIJKSTRA
#define ALGORITHM_DIJKSTRA

#include <vector>
#include "graph_node.h"

namespace algorithm
{
	namespace graph
	{
		void dijkstra(int from, int* parent, int* distance, const std::vector<std::vector<Node>>& graph);
	}
}

#endif // ALGORITHM_DIJKSTRA