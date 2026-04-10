#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans;

    for (int i = 0; i<n; i++) {
       long long a_i = a[i];

       vector<long long> e;

       int b = 0;

       for (int k = i + 1; k < n; k++) {
           long long a_j = a[k];
           long long mid = a_i + a_j;

           if (a_j < a_i) {
               e.push_back(mid*2);
               b++;
       } else if (a_j > a_i) {
            e.push_back((mid*2)+1);
       }
    }

    sort(e.begin(), e.end());

    int current = b;
    int best = current;

    for (long long x : e) {
        if (x & 1) {
            current++;
        } else {
            current--;
        }
        best = max(best, current);
    }
    ans.push_back(best);
    }

    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
