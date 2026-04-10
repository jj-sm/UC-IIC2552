#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */

void solve() {
    long long n, c, k;
    cin >> n >> c >> k;

    vector<long long> monsters(n);
    for (int i = 0; i < n; i++) {
        cin >> monsters[i];
    }

    sort(monsters.begin(), monsters.end());

    for (const auto& item : monsters){
        if (item <= c) {
            long long ff_prob = min(k, c - item);
            c += item + ff_prob;
            k -= ff_prob;
        } else {
            break;
        }
    }
    cout << c << "\n";
}
   
// Kill an alive monster 𝑖 if 𝑎𝑖≤𝑐; then 𝑐 becomes 𝑐+𝑎𝑖.
// Throw a flip flop at an alive monster 𝑖; the flip-flop will be broken and the monster will become angrier, then 𝑎𝑖 becomes ai + 1    




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
