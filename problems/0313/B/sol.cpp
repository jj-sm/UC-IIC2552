#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int n, q;
    cin >> n >> q;

    vector<int> goals(n);
    vector<int> queries(q);

    for (int i = 0; i < n; i++) {
        cin >> goals[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    for (int i = 0; i < q; i++) {
        vector<int>::iterator idx = upper_bound(goals.begin(), goals.end(), queries[i]);
        cout << (idx - goals.begin()) << " ";
    }

    return 0;
}
