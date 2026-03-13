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

    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    int current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += h[i];
    } 

    int min_sum = current_sum;
    int min_idx = 1;

    for (int i = k; i < n; i++) {
        current_sum = current_sum + h[i] - h[i-k];
        if (current_sum < min_sum) {
            min_sum = current_sum;
            min_idx = i - k + 2;
        }
    }

    cout << min_idx << "\n";

    return 0;
}
