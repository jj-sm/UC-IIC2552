//  B. Sushi para Dos
/**
 * Problem: B_Sushi_para_Dos.cpp
 * Date:    24/04/26
 * Compile: g++ -std=c++23 -O2 B_Sushi_para_Dos.cpp -o out
 * Run:     ./out < input.txt
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
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
    int n;
    cin >> n;

    vi sush(n);
    for (int i = 0; i < n; i++) {
        cin >> sush[i];
    }

    int prev = 0;
    int actual = 1;
    int best = 0;

    for (int i = 1; i < n; i++) {
        if (sush[i] == sush[i - 1]) {
            actual++;
        } else {
            best = max(best, 2 * min(prev, actual));
            prev = actual;
            actual = 1;
        }
    }

    best = max(best, 2 * min(prev, actual));
    cout << best << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}
