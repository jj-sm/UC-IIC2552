//  B. Fotosíntesis
/**
 * Problem: sol.cpp
 * Date:    10/04/26
 * Compile: g++ -std=c++23 -O2 sol.cpp -o out
 * Run:     ./out < input.txt
 */

#include <iostream>
#include <vector>

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
bool posible = true;

void dfs(int nodo) {
    if (adj[nodo].empty()) return;

    int hojas_hijas = 0;
    for (auto u : adj[nodo]) {
        dfs(u);
        if (adj[u].empty()) {
            hojas_hijas++;
        }
    }
    if (hojas_hijas < 3) {
        posible = false;
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    adj.assign(n + 1, vi());
    posible = true;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].pb(i);
    }
    dfs(1);

    if (posible) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}