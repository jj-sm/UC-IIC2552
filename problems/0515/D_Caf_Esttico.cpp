//  D. Café Estético
/**
 * Problem: D_Caf_Esttico.cpp
 * Date:    29/05/26
 * Compile: g++ -std=c++23 -O2 D_Caf_Esttico.cpp -o out
 * Run:     ./out < input.txt
 */

#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <numeric>

using namespace std;

// --- Macros ---
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second


// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mxN = 2e5+5, M = 1e9+7;

class Dinic{
    struct Edge { int to, rev; ll f, c; };

    int n, t_; vector<vector<Edge>> G;
    vl D; vi q, W;
    bool bfs(int s, int t){
        W.assign(n, 0); D.assign(n, -1); D[s] = 0;
        int f = 0, l = 0; q[l++] = s;
        while (f < l){
            int u = q[f++];
            for (const Edge &e : G[u]) if (D[e.to] == -1 && e.f < e.c)
                D[e.to] = D[u] + 1, q[l++] = e.to;
        }
        return D[t] != -1;
    }
    ll dfs(int u, ll f){
        if (u == t_) return f;
        for (int &i = W[u]; i < (int)G[u].size(); ++i){
            Edge &e = G[u][i]; int v = e.to;
            if (e.c <= e.f || D[v] != D[u] + 1) continue;
            ll df = dfs(v, min(f, e.c - e.f));
            if (df > 0) { e.f += df, G[v][e.rev].f -= df; return df; }
        }
        return 0;
    }

public:
    Dinic(int N) : n(N), G(N), D(N), q(N) {}
    void addEdge(int u, int v, ll cap){
        G[u].push_back({v, (int)G[v].size(), 0, cap});
        G[v].push_back({u, (int)G[u].size() - 1, 0, 0}); // cap if bidirectional
    }
    ll maxFlow(int s, int t){
        t_ = t; ll ans = 0;
        while (bfs(s, t)) while (ll dl = dfs(s, LLONG_MAX)) ans += dl;
        return ans;
    }
};

void solve(){
    int c, p, e;
    cin >> c >> p >> e;

    vi demandas(c);
    vi stocks(p);
    vi tiempos;

    for (int i = 0; i < c; ++i)
        cin >> demandas[i];

    for (int i = 0; i < p; ++i)
        cin >> stocks[i];

    vector<tuple<int,int,int>> edges(e);

    for (int i = 0; i < e; ++i) {
        int cafe, plant, t;
        cin >> cafe >> plant >> t;
        cafe--; plant--;
        edges[i] = {cafe, plant, t};
        tiempos.pb(t);
    }

    sort(all(tiempos));
    tiempos.erase(unique(all(tiempos)), tiempos.end());

    int total_demanda = accumulate(all(demandas), 0);

    int S = 0;
    int T = p + c + 1;


    int l = 0;
    int r = sz(tiempos) - 1;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        int t_max = tiempos[mid];

        Dinic dinic(T + 1);
        for (int i = 0; i < p; ++i)
            dinic.addEdge(S, 1 + i, stocks[i]);

        for (int i = 0; i < c; ++i)
            dinic.addEdge(p + 1 + i, T, demandas[i]);

        for (auto& [cafe, plant, t]: edges)
            if (t <= t_max)
                dinic.addEdge(1 + plant, p + 1 + cafe, 1e9);

        if (dinic.maxFlow(S, T) == total_demanda) {
            ans = t_max;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--){
        solve();
    }
}