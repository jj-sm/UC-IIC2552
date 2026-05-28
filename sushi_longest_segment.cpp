#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    vector<int> runs;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (t[i] == t[i - 1]) {
            ++cnt;
        } else {
            runs.push_back(cnt);
            cnt = 1;
        }
    }
    runs.push_back(cnt);

    int ans = 0;
    for (int i = 1; i < (int)runs.size(); ++i) {
        ans = max(ans, 2 * min(runs[i - 1], runs[i]));
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
