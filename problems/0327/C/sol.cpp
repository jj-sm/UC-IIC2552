#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */

void solve() {
    int n_nodos, n_aristas;

    cin >> n_nodos >> n_aristas;
    vector<vector<int>> edges(n_nodos + 1);

    for (int i = 0; i < n_aristas; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> dist(n_nodos + 1, -1);
    vector<int> nod_par, nod_impar;
    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (dist[curr] % 2 == 0) {
            nod_par.push_back(curr);
        } else {
            nod_impar.push_back(curr);
        }

        for (int v : edges[curr]) {
            if (dist[v] == -1) {
                dist[v] = dist[curr] + 1;
                q.push(v);
            }
        }
    }

    vector<int>& chosen = (nod_par.size() <= (size_t)(n_nodos / 2)) ? nod_par : nod_impar;

    cout << chosen.size() << "\n";
    for (int i = 0; i < (int)chosen.size(); i++) {
        cout << chosen[i] << (i == (int)chosen.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
