#include "dfs.h"
#include <stack>

namespace Algorithm
{
	namespace Dfs
	{
		bool dfsSearchIterative(int start, int end, std::vector<std::vector<int>>& graph)
		{
			if (start == end)
			{
				return true;
			}

			std::stack<int> s;
			s.push(start);

			std::vector<int> used(graph.size(), 0);

			while (!s.empty())
			{
				int top = s.top();
				s.pop();
				used[top] = 1;

				for (int i = 0; i < graph[top].size(); ++i)
				{
					int node = graph[top][i];

					if (node == end)
					{
						return true;
					}

					if (!used[node])
					{
						s.push(node);
					}
				}
			}

			return false;
		}

		bool dfsSearchRecursive(int start, int end, std::vector<std::vector<int>>& graph, std::vector<int>& used)
		{
			if (start == end)
				return true;

			used[start] = 1;

			for (int i = 0; i < graph[start].size(); ++i)
			{
				int node = graph[start][i];

				if (node == end)
				{
					return true;
				}

				if (!used[node])
				{
					if (dfsSearchRecursive(node, end, graph, used))
					{
						return true;
					}
				}
			}
		}
	}
}

/*
int main() {

    int nodeCount;
    int edgeCount;

	std::cout << "Enter node count and edge count: ";
	std::cin >> nodeCount >> edgeCount;

	std::vector<std::vector<int>> graph(nodeCount);

	std::cout << "Enter from, to: ";
    for(int i = 0; i < edgeCount; ++i) {
        int from, to;
		std::cin >> from >> to;

        graph[from - 1].push_back(to - 1);
    }

    int start, end;
	std::cout << "Enter starting node and the node to search: " ;
	std::cin >> start >> end;

    
    // iterative way    
	std::cout << Dfs::dfsSearchIterative(start - 1, end - 1, graph) << std::endl;

    
    //recursive way    
	std::vector<int> used(nodeCount, 0);
	std::cout << Dfs::dfsSearchRecursive(start - 1, end - 1, graph, used) << std::endl;

	return 0;
}
*/