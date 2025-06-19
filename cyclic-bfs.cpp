#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<pair<int, int>> q;
    visited[start] = true;
    q.push({start, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            if (graph[node][i]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push({i, node});
                } else if (i != parent) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool isCyclicBFS(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i] && bfs(i, graph, visited))
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

    cout << "\n[BFS] ";
    if (isCyclicBFS(graph))
        cout << "Graph contains a cycle." << endl;
    else
        cout << "Graph does NOT contain a cycle." << endl;

    return 0;
}
