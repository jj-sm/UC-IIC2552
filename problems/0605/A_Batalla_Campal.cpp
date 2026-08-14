//  A. Batalla Campal
/**
 * Problem: A_Batalla_Campal.cpp
 * Date:    19/06/26
 * Compile: g++ -std=c++23 -O2 A_Batalla_Campal.cpp -o out
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

struct ST {
    int n;
    vector<ll> st;

    ST(int N) {
        n = N;
        st.resize(4 * n);
    }

    ll query(int L, int R) {
        return query(1, L, R, 0, n - 1);
    }

    ll query(int node, int L, int R, int Lu, int Ru) {
        if (R < Lu || Ru < L) {
            return -1e18;
        }

        if (L <= Lu && Ru <= R) {
            return st[node];
        }

        int m = (Lu + Ru) / 2;

        return max(query(2 * node, L, R, Lu, m), query(2 * node + 1, L, R, m + 1, Ru));
    }

    void update(int i, ll x) {
        update(1, i, x, 0, n - 1);
    }

    void update(int node, int i, ll x, int Lu, int Ru) {
        if (i < Lu || i > Ru) return;

        if (Lu == Ru) {
            st[node] = x;
            return;
        }

        int m = (Lu + Ru) / 2;

        update(2 * node, i, x, Lu, m);
        update(2 * node + 1, i, x, m + 1, Ru);

        st[node] = max(st[2 * node], st[2 * node + 1]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    ST st(n);

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        st.update(i, x);
    }

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int k;
            ll u;
            cin >> k >> u;
            k--;
            st.update(k, u);
        } else {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            cout << st.query(a, b) << "\n";
        }
    }
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
