//  D. Decodificar el Bit
/**
 * Problem: D_Decodificar_el_Bit.cpp
 * Date:    19/06/26
 * Compile: g++ -std=c++23 -O2 D_Decodificar_el_Bit.cpp -o out
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
    int sz;
    vector<unsigned int> st;
    vector<bool> isOr;

    ST(int N) {
        n = N;
        sz = 1 << n;
        st.resize(2 * sz);
        isOr.resize(2 * sz);

        for (int i = 1; i < 2 * sz; i++) {
            int depth = 31 - __builtin_clz(i);
            int level = n - depth;
            isOr[i] = (level % 2 == 1);
        }
    }

    void build(vector<unsigned int>& a) {
        for (int i = 0; i < sz; i++) st[sz + i] = a[i];
        for (int i = sz - 1; i >= 1; i--) {
            st[i] = isOr[i] ? (st[2 * i] | st[2 * i + 1])
                             : (st[2 * i] ^ st[2 * i + 1]);
        }
    }

    void update(int pos, unsigned int val) {
        int i = sz + pos;
        st[i] = val;
        i >>= 1;
        while (i >= 1) {
            st[i] = isOr[i] ? (st[2 * i] | st[2 * i + 1])
                             : (st[2 * i] ^ st[2 * i + 1]);
            i >>= 1;
        }
    }

    unsigned int root() {
        return st[1];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    int total = 1 << n;
    vector<unsigned int> a(total);
    for (int i = 0; i < total; i++) cin >> a[i];

    ST st(n);
    st.build(a);

    while (m--) {
        int p;
        unsigned int b;
        cin >> p >> b;
        p--;
        st.update(p, b);
        cout << st.root() << "\n";
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
