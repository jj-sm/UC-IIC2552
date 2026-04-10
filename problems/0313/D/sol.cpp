#include <iostream>
#include <vector>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_types;
    long long k_cupons;

    cin >> n_types;
    cin >> k_cupons;

    vector<long long> needed_i(n_types, 0);
    vector<long long> stock_i(n_types, 0);

    for (int i = 0; i < n_types; i++) {
        cin >> needed_i[i];
    }
    for (int i = 0; i < n_types; i++) {
        cin >> stock_i[i];
    }

    long long robots = 0;

    long long bottom = 0;
    long long ceiling = 2e9;
    ceiling++;

    while (bottom <= ceiling) {
        long long mid = (bottom + ceiling) / 2;
        long long temu_needed = 0;        

        

        for (int i = 0; i < n_types; i++) {
            long long parts_missing = mid * needed_i[i];

            if (parts_missing > stock_i[i]) {
                temu_needed += (parts_missing - stock_i[i]);
            }

            if (temu_needed > k_cupons) {
                break;
            }
        }

        

        if (temu_needed <= k_cupons) {
            robots = mid;
            bottom = mid + 1;
        } else {
            ceiling = mid - 1;  
        }
    }


    cout << robots << "\n";
}
