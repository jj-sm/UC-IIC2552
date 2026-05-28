//  G. Conecta Nlogonia
/**
 * Compile: g++ -std=c++23 -O2 G_Conecta_Nlogonia.cpp -o out
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    // Safe I/O read that gracefully exits if the runner feeds empty input
    if (!(cin >> n >> m)) return;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> dfn(n + 1, 0), low(n + 1, 0), scc(n + 1, 0), st;
    vector<bool> in_st(n + 1, false);
    int timer = 0, scc_cnt = 0;

    // C++23 Recursive Lambda for Tarjan's Algorithm
    auto tarjan = [&](auto& self, int u) -> void {
        dfn[u] = low[u] = ++timer;
        st.push_back(u);
        in_st[u] = true;

        for (int v : adj[u]) {
            if (!dfn[v]) {
                self(self, v);
                low[u] = min(low[u], low[v]);
            } else if (in_st[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }

        if (low[u] == dfn[u]) {
            scc_cnt++;
            int v;
            do {
                v = st.back();
                st.pop_back();
                in_st[v] = false;
                scc[v] = scc_cnt;
            } while (v != u);
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(tarjan, i);
    }

    if (scc_cnt == 1) {
        cout << 0 << "\n";
        return;
    }

    vector<int> in_degree(scc_cnt + 1, 0), out_degree(scc_cnt + 1, 0);

    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (scc[u] != scc[v]) {
                out_degree[scc[u]]++;
                in_degree[scc[v]]++;
            }
        }
    }

    int zero_in = 0, zero_out = 0;

    for (int i = 1; i <= scc_cnt; i++) {
        if (in_degree[i] == 0) zero_in++;
        if (out_degree[i] == 0) zero_out++;
    }

    cout << max(zero_in, zero_out) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}