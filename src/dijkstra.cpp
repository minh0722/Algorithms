#include "dijkstra.h"
#include "graph_node.h"
#include <vector>
#include <queue>

namespace Algorithm
{
	namespace Dijkstra
	{
		// distance from node to every other nodes are kept in distance array
		void dijkstra(int from, int* parent, int* distance, const std::vector<std::vector<Node>>& graph)
		{
			std::priority_queue<Node> pq;
			pq.push(Node(from, from, 0));

			while (!pq.empty())
			{
				Node current = pq.top();
				pq.pop();

				if (parent[current.to] != -1)
				{
					continue;
				}
				else
				{
					parent[current.to] = current.from;
					distance[current.to] = current.weight;
				}

				for (int i = 0; i < graph[current.to].size(); ++i)
				{
					if (parent[graph[current.to][i].to] == -1)
					{
						pq.push(Node(current.to, graph[current.to][i].to, distance[current.to] + graph[current.to][i].weight));
					}
				}
			}
		}
	}
}

/*int main() {

    int nodeCount, edgeCount;
    scanf("%d %d", &nodeCount, &edgeCount);

	std::vector<std::vector<Algorithm::Node> > graph(nodeCount);

    for(int i = 0; i < edgeCount; ++i) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);

        graph[from - 1].push_back(Algorithm::Node(from - 1, to - 1, weight));
        graph[to - 1].push_back(Algorithm::Node(to - 1, from - 1, weight));
    }

    int* parent = new int[nodeCount];
    memset(parent, -1, nodeCount * sizeof(int));

    int* distance = new int[nodeCount];
    memset(distance, INT_MAX, nodeCount * sizeof(int));

    Algorithm::dijkstra(0, parent, distance, graph);

	std::cout << "parent: ";
    for(int i = 0; i < nodeCount; ++i)
	{
		std::cout << parent[i] + 1 << " ";
    }
	std::cout << std::endl;

	std::cout << "distance: ";
    for(int i = 0; i < nodeCount; ++i) 
	{
		std::cout << distance[i] << " ";
    }
	std::cout << std::endl;

return 0;
}
*/
