#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool dfsSearchIterative(int start, int end, vector<vector<int>>& graph) {
    if(start == end) {
        return true;
    }
    
    stack<int> s;
    s.push(start);
    
    vector<int> used(graph.size(), 0);
    
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        used[top] = 1;
        

        for(int i = 0; i < graph[top].size(); ++i) {
            int node = graph[top][i];
            
            if(node == end) {
                return true;
            }
            
            if(!used[node]) {
                s.push(node);
            }
        }
    }

    return false;
}

bool dfsSearchRecursive(int start, int end, vector<vector<int>>& graph, vector<int>& used) {
    if(start == end)
        return true;
    
    used[start] = 1;
    
    for(int i = 0; i < graph[start].size(); ++i) {
        int node = graph[start][i];

        if(node == end) {
            return true;
        }
        
        if(!used[node]) {
            if(dfsSearchRecursive(node, end, graph, used)) {
                return true;
            }
        }
    }
}

int main() {

    int nodeCount;
    int edgeCount;

    cout << "Enter node count and edge count: ";
    cin >> nodeCount >> edgeCount;

    vector<vector<int>> graph(nodeCount);

    cout << "Enter from, to: ";
    for(int i = 0; i < edgeCount; ++i) {
        int from, to;
        cin >> from >> to;

        graph[from - 1].push_back(to - 1);
    }

    int start, end;
    cout << "Enter starting node and the node to search: " ;
    cin >> start >> end;

    /*
     * iterative way
    */
    cout << dfsSearchIterative(start - 1, end - 1, graph) << endl;

    /*
     * recursive way
    */
    vector<int> used(nodeCount, 0);
    cout << dfsSearchRecursive(start - 1, end - 1, graph, used) << endl;

return 0;
}