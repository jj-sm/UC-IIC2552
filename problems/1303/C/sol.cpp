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
    
    int cant_amigos;
    cin >> cant_amigos;

    vector<int> alt(cant_amigos);
    for (int i = 0; i < cant_amigos; i++) {
        cin >> alt[i];
    }

    sort(alt.begin(), alt.end());

    int count_pairs = 0;
    int idx_carried = 0;
    int half = cant_amigos / 2;

    for (int i = half; i < cant_amigos; i++) {
        if (idx_carried < half && alt[i] >= 2 * alt[idx_carried]) {
            count_pairs++;
            idx_carried++;
        }
    }

    cout << cant_amigos - count_pairs << "\n";

    return 0;
}
