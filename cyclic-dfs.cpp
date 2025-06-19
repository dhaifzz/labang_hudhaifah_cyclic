#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node, graph, visited)) return true;
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCyclicDFS(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfs(i, -1, graph, visited))
            return true;
    }
    return false;
}

int main() {
    int n;
    cout << "Enter number of vertices (example 3 for 3x3): ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "\nAdjacency Matrix:\n   ";
    for (int i = 0; i < n; i++) cout << i << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n[DFS] ";
    if (isCyclicDFS(graph))
        cout << "Graph contains a cycle." << endl;
    else
        cout << "Graph does NOT contain a cycle." << endl;

    return 0;
}
