#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edges;
vector<int> visited;

void dfs(int nodo){
    visited[nodo] = 1;
    for (auto u : edges[nodo]) {
        if (visited[u] == 0) {
            dfs(u);
        }
    }
    visited[nodo] = 2;
}

int main(){
    int n, m;
    cin >> n >> m;

    edges.resize(n);
    visited.resize(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; 
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(0);


}
