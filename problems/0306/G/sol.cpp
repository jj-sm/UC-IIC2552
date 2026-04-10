#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */

bool can_jump(int actual_col, int n_cols, int h_actual, int h_next, int max_jump) {
    if (actual_col < n_cols && abs(h_actual - h_next) <= max_jump) {
    return true; 
    } else {
        return false;
    }
}

void solve() {
    int n;
    int m;
    int k;
    cin >> n;
    cin >> m;
    cin >> k;

    vector<int> cols(n);
    for (int i = 0; i < n; i++) {
        cin >> cols[i];
    }

    for (int i = 0; i < n - 1; i++) {
        // check quitar bloques y gdduardarlos
        int h_act = cols[i];
        int h_next = cols[i + 1];
        int h_min = max(0, h_next - k);

        if (h_act >= h_min) {
            m += (h_act - h_min);
        } else {
            int m_needed = h_min - h_act;

            if (m >= m_needed) {
                m -= m_needed;
            } else {
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned short int n;
    cin >> n;

    while (n--) {
        solve();
    }

    return 0;
}
