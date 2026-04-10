#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */

void solve() {
    int cant_vecinos, cant_vinculos;
    cin >> cant_vecinos >> cant_vinculos;

    vector<vector<int>> vecinos(cant_vecinos + 1);

    for (int i = 0; i < cant_vinculos; i++) {
        int u, v;
        cin >> u >> v;
        vecinos[u].push_back(v);
        vecinos[v].push_back(u);
    }

    for (int i = 1; i <= cant_vecinos; i++) {

        sort(vecinos[i].begin(), vecinos[i].end());

        int k_i = vecinos[i].size();
        cout << k_i;

        for (int vecino : vecinos[i]) {
            cout << ' ' << vecino;
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
