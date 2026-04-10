#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> edges;
vector<int> visited;

void dfs_iterative(int start_node) {
    // Stack stores: {current_node, neighbor_index}
    stack<pair<int, int>> s;

    s.push({start_node, 0});
    visited[start_node] = 1; // Mark as "visiting"

    while (!s.empty()) {
        int nodo = s.top().first;
        int neighbor_idx = s.top().second;
        s.pop();

        // If we still have neighbors to explore
        if (neighbor_idx < edges[nodo].size()) {
            // Put the current node back with the NEXT neighbor index
            s.push({nodo, neighbor_idx + 1});

            int u = edges[nodo][neighbor_idx];
            if (visited[u] == 0) {
                visited[u] = 1; // Mark neighbor as "visiting"
                s.push({u, 0});  // Push the neighbor to start its exploration
            }
        } else {
            // No more neighbors left, we are done with this node
            visited[nodo] = 2; // Mark as "fully visited"
        }
    }
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    edges.resize(n);
    visited.resize(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    if (n > 0) dfs_iterative(0);

    return 0;
}
