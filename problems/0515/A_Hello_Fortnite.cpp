//  A. Hello Fortnite
/**
 * Problem: A_Hello_Fortnite.cpp
 * Date:    28/05/26
 * Compile: g++ -std=c++23 -O2 A_Hello_Fortnite.cpp -o out
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
    int n, m;
    cin >> n >> m;
    Dinic dinic(n);
    for(int i = 0; i<m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        dinic.addEdge(u, v, c);
    }

    cout << dinic.maxFlow(0, n-1) << "\n";

}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--){
        solve();
    }
}