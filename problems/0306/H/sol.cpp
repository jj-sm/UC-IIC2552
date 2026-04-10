#include <iostream>
#include <deque>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */


long long deque2Int(const deque<int> & d) {
    int result = 0;
    for (int digit : d) {
        result = (result * 10) + digit;
    }
    return result;
}


void solve() {
    string num;
    cin >> num;

    int n_digits = num.size();
    int n_digits_half = n_digits / 2;

    deque<int> res_even_deq;
    deque<int> res_odd_deq;

    for (int i = 1; i < n_digits + 1; i++) {
        char c = num[n_digits - i];
        int idx = i - 1;

        if (idx % 2 == 0) {
            res_even_deq.push_front(c - '0');
        } else {
            res_odd_deq.push_front(c - '0');
        }
    }

    long long int_odd = deque2Int(res_odd_deq);
    long long int_even = deque2Int(res_even_deq);

    long long ans = (int_odd + 1) * (int_even + 1) - 2;

    // cout << "->" << num << "\n";
    //
    // cout << int_odd << " y " << int_even << "\n";

    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned short int t;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}
