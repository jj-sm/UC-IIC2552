#include <iostream>
#include <algorithm>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned short int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        int n_students;
        cin >> n_students;

        int time = 0;
        for (int k = 0; k < n_students; k++) {
            int l, r;
            cin >> l >> r;

            time = max(time, l);
            if (r < time) {
                cout << "0" << " ";
            } else {
                cout << time << " ";
                time++;
            }
        }

        cout << "\n";
    
    }




    return 0;
}
