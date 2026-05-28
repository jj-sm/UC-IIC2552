//  G. Conecta Nlogonia
/**
 * Problem: G_Conecta_Nlogonia.cpp
 * Date:    24/04/26
 * Compile: g++ -std=c++23 -O2 G_Conecta_Nlogonia.cpp -o out
 * Run:     ./out < input.txt
 */

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

    vector<pair<bool,bool>> io_nodos(n, {false, false});

    if (m == 0) {
        cout << n; return;
    }

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        io_nodos[from].second = true;
        io_nodos[to].first = true;
    }

    int missing = 0;
    for (int i = 0; i < n; i++) {
        if (io_nodos[i].second == false) {
            missing++;
        }
    }

    cout << missing << endl;


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
