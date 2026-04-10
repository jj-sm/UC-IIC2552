#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned int n_montones;
    cin >> n_montones;

    vector<int> frugeles(n_montones);
    for (int i = 0; i < n_montones; i++) {
        cin >> frugeles[i];
     } 

    unsigned int n_speci;
    cin >> n_speci;

    vector<int> special(n_speci);
    for (int i = 0; i < n_speci; i++) {
        cin >> special[i];
    }

    vector<int> tags(n_montones + 1);
    tags[0] = 1;

    for (int i = 0; i < n_montones; i++) {
        tags[i + 1] = frugeles[i] + tags[i];
    }

    for (int i = 0; i < n_speci; i++) {
        vector<int>::iterator idx = upper_bound(tags.begin(), tags.end(), special[i]);
        cout << (idx - tags.begin()) << "\n";
    }

    return 0;
}

