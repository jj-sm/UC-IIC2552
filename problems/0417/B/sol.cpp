//  B. Ruta 113
/**
 * Problem: sol.cpp
 * Date:    24/04/26
 * Compile: g++ -std=c++23 -O2 sol.cpp -o out
 * Run:     ./out < input.txt
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <iomanip>

using namespace std;

// --- Macros ---
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> edges(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[u].pb({v, w});
        edges[v].pb({u, w});
    }

    ll INF = 1e18;
    vll distancia(n, INF);
    vi padre(n, -1);
    priority_queue<pll, vector<pll>, greater<pll>> q;

    distancia[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();

        if (d > distancia[u]) continue;

        for (auto &[v, w] : edges[u]) {
            if (distancia[u] + w < distancia[v]) {
                distancia[v] = distancia[u] + w;
                padre[v] = u;
                q.push({distancia[v], v});
            }
        }
    }

    if (distancia[n - 1] == INF) {
        cout << -1 << "\n";
        return;
    }

    vi camino;
    for (int cur = n-1; cur != -1; cur = padre[cur]) {
        camino.pb(cur + 1);
    }
    reverse(all(camino));

    for (int i = 0; i < sz(camino); i++) {
        cout << camino[i];
        if (i < sz(camino)-1) cout << " ";
    }
    cout << "\n";
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
