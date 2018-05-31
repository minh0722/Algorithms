#include "dijkstrav2.h"
#include "graph_node.h"
#include <vector>
#include <queue>

namespace algorithm
{
    namespace graph
    {
        // distance from node to every other nodes are kept in distance array
        void dijkstrav2(const std::vector<std::vector<Nodev2> >& graph, int* distance, int from)
        {
            std::priority_queue<Nodev2> pq;
            pq.push(Nodev2(from, 0));

            char* used = new char[graph.size()];
            memset(used, 0, graph.size() * sizeof(char));

            int dist = 0;

            while (!pq.empty())
            {
                Nodev2 current = pq.top();
                pq.pop();
                used[current.num] = 1;

                for (size_t i = 0; i < graph[current.num].size(); ++i)
                {
                    if (!used[graph[current.num][i].num])
                    {
                        pq.push(Nodev2(graph[current.num][i].num, graph[current.num][i].weight + distance[current.num]));
                    }

                    if (distance[graph[current.num][i].num] < distance[current.num] + graph[current.num][i].weight)
                    {
                        distance[graph[current.num][i].num] = distance[current.num] + graph[current.num][i].weight;
                    }

                    if (dist < distance[graph[current.num][i].num])
                    {
                        dist = distance[graph[current.num][i].num];
                    }
                }
            }

            // TODO: consider return it as a max distance
            int maxDist = dist;
        }
    }
}

//int main() 
//{
//
//    int nodeCount, edgeCount;
//    scanf("%d %d", &nodeCount, &edgeCount);
//
//    vector<vector<Node> > graph(nodeCount);
//
//    for(int i = 0; i < edgeCount; ++i)
//    {
//        int from, to, weight;
//        scanf("%d %d %d", &from, &to, &weight);
//
//        graph[from - 1].push_back(Node(to - 1, weight));
//    }
//
//    int maxDist = 0;
//    
//    int* distance = new int[graph.size()];
//    memset(distance, 0, graph.size() * sizeof(int));
//    
//    dijkstrav2(graph, distance, 0);
//
//return 0;
//}