struct Node {
    Node(int n, int w) : num(n), weight(w) {}
    Node() : num(0), weight(0) {}

    bool operator<(const Node& n)const {
        return weight < n.weight;
    }

    int num, weight;
};

// distance from node to every other nodes are kept in distance array
void dijkstra(const vector<vector<Node> >& graph, int* distance, int from) {
    priority_queue<Node> pq;
    pq.push(Node(from, 0));

    char* used = new char[graph.size()];
    memset(used, 0, graph.size() * sizeof(char));

    int dist = 0;

    while(!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        used[current.num] = 1;

        for(int i = 0; i < graph[current.num].size(); ++i) {
            if( !used[graph[current.num][i].num] ) {
                pq.push( Node(graph[current.num][i].num, graph[current.num][i].weight + distance[current.num]) );
            }

            if(distance[graph[current.num][i].num] < distance[current.num] + graph[current.num][i].weight) {
                distance[graph[current.num][i].num] = distance[current.num] + graph[current.num][i].weight;
            }

            if(dist < distance[graph[current.num][i].num]) {
                dist = distance[graph[current.num][i].num];
            }
        }
    }

    maxDist = dist;
}

int main() {

    int nodeCount, edgeCount;
    scanf("%d %d", &nodeCount, &edgeCount);

    vector<vector<Node> > graph(nodeCount);

    for(int i = 0; i < edgeCount; ++i) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);

        graph[from - 1].push_back(Node(to - 1, weight));
    }

    int maxDist = 0;
    
    int* distance = new int[graph.size()];
    memset(distance, 0, graph.size() * sizeof(int));
    
    dijkstra(graph, distance, 0);



return 0;
}