#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <climits>
#include <utility>
#include <cstring>
#include <stdio.h>
using namespace std;

struct Node {
    int from, to, weight;

    Node(int f, int t, int w) : from(f), to(t), weight(w) {}
    Node() : from(0), to(0), weight(0) {}

    bool operator<(const Node& n) const {
        return weight > n.weight;
    }
};

// distance from node to every other nodes are kept in distance array
void dijkstra(int from, int* parent, int* distance, const vector<vector<Node> >& graph) {
    priority_queue<Node> pq;
    pq.push(Node(from, from, 0));

    while(!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if(parent[current.to] != -1) {
            continue;
        }
        else {
            parent[current.to] = current.from;
            distance[current.to] = current.weight;
        }

        for(int i = 0; i < graph[current.to].size(); ++i) {
            if(parent[ graph[current.to][i].to ] == -1) {
                pq.push(Node(current.to, graph[current.to][i].to, distance[current.to] + graph[current.to][i].weight) );
            }
        }

    }

}

int main() {

    int nodeCount, edgeCount;
    scanf("%d %d", &nodeCount, &edgeCount);

    vector<vector<Node> > graph(nodeCount);

    for(int i = 0; i < edgeCount; ++i) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);

        graph[from - 1].push_back(Node(from - 1, to - 1, weight));
        graph[to - 1].push_back(Node(to - 1, from - 1, weight));
    }

    int* parent = new int[nodeCount];
    memset(parent, -1, nodeCount * sizeof(int));

    int* distance = new int[nodeCount];
    memset(distance, INT_MAX, nodeCount * sizeof(int));

    dijkstra(0, parent, distance, graph);

    cout << "parent: ";
    for(int i = 0; i < nodeCount; ++i) {
        cout << parent[i] + 1 << " ";
    }cout << endl;

    cout << "distance: ";
    for(int i = 0; i < nodeCount; ++i) {
        cout << distance[i] << " ";
    }cout << endl;

return 0;
}
