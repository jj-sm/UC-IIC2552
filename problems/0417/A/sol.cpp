//  A. BTS
/**
 * Problem: sol.cpp
 * Date:    24/04/26
 * Compile: g++ -std=c++23 -O2 sol.cpp -o out
 * Run:     ./out < input.txt
 */

#include <iostream>
#include <vector>
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

    vll w(n);
    for(int i = 0; i < n; i++) cin >> w[i];

    vector<vi> edges(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    priority_queue<pll, vector<pll>, greater<pll>> q;
    vll distancia(n, 1e18);
    distancia[0] = w[0];
    q.push({distancia[0], 0});

    while(!q.empty()){
        auto [d, u] = q.top();
        q.pop();

        if(d > distancia[u]) continue;

        for(auto &v : edges[u]){
            if(distancia[u] + w[v] < distancia[v]){
                distancia[v] = distancia[u] + w[v];
                q.push({distancia[v], v});
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << (distancia[i] >= (ll)1e18 ? - 1 : distancia[i]);
        if(i < n-1) cout << " ";
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