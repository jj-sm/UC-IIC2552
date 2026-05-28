//  C. Goma López
/**
 * Problem: sol.cpp
 * Date:    17/04/26
 * Compile: g++ -std=c++23 -O2 sol.cpp -o out
 * Run:     ./out < input.txt
 */

#include <iostream>
#include <vector>
#include <algorithm>

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

vector<vi> adj;
int max_depth = 0;

void dfs(int nodo, int d) {
    max_depth = max(max_depth, d);
    for (int hijo : adj[nodo]) {
        dfs(hijo, d + 1);
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    adj.assign(n + 1, vi());
    vi init;

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p == -1) {
            init.pb(i);
        } else {
            adj[p].pb(i);
        }
    }

    for (int r : init) {
        dfs(r, 1);
    }

    cout << max_depth << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}