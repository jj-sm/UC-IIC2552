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
    
    unsigned short int n_names;
    cin >> n_names;

    map<string, int> students;

    for (int i = 0; i < n_names; i++) {
        string in;
        cin >> in;
        if (students.find(in) != students.end()) {
            cout << "YES" << "\n";
            students[in]++;
        } else {
            cout << "NO" << "\n";
            students[in] = 0;
        }
    }





    return 0;
}
