#ifndef ALGORITHM_DFS
#define ALGORITHM_DFS

#include <vector>
#include <map>
#include "graph_node.h"
#include "common.h"

namespace algorithm
{
	namespace graph
	{
		ALGO_API bool dfsSearchAdjList(int start, int end, std::map<int, std::vector<Nodev2>>& graph);
		ALGO_API bool dfsSearchIterative(int start, int end, std::vector<std::vector<int> >& graph);
        ALGO_API bool dfsSearchRecursive(int start, int end, std::vector<std::vector<int> >& graph, std::vector<int>& used);
	}
}
#endif // ALGORITHM_DFS