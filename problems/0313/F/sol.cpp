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
    // Your logic here
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n_cities;
    int n_antennas;

    cin >> n_cities;
    cin >> n_antennas;

    vector<int> cities(n_cities);
    vector<int> antennas(n_antennas);

    for (int i = 0; i < n_cities; i++) {
        cin >> cities[i];
    }

    for (int i = 0; i < n_antennas; i++) {
        cin >> antennas[i];
    }

    int l = 0;
    int r = 1e9 + 1;
    int r_min = 0;

    for (int i = 0; i < n_cities; i++) {
        auto idx = lower_bound(antennas.begin(), antennas.end(), cities[i]);

        int r_max = 2e9;

        if (idx != antennas.end()) {
            r_max = min(r_max, *idx - cities[i]);
        }

        if (idx != antennas.begin()) {
            auto prev_idx = idx - 1;
            r_max = min(r_max, cities[i] - *prev_idx);
        }

        r_min = max(r_min, r_max);
    }


    cout << r_min << "\n";


    return 0;
}
