#ifndef ALGORITHM_DFS
#define ALGORITHM_DFS

#include <vector>

namespace algorithm
{
	namespace graph
	{
		bool dfsSearchIterative(int start, int end, std::vector<std::vector<int>>& graph);
		bool dfsSearchRecursive(int start, int end, std::vector<std::vector<int>>& graph, std::vector<int>& used);
	}
}
#endif // ALGORITHM_DFS