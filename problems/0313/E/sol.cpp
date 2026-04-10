#include <ios>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_amigos;

    cin >> n_amigos;

    vector<int> pos(n_amigos);
    vector<int> vel(n_amigos);

    for (int i = 0; i < n_amigos; i++) {
        cin >> pos[i];
    }
    for (int i = 0; i < n_amigos; i++) {
        cin >> vel[i];
    }

    double l = 0;
    double r = 1e9;

    int counter = 100;

    while (counter--) {
        double mid = (l + r) / 2.0;
        
        double l_max = -1e9 + 1;
        double r_max = 1e9 + 1;

        for (int i = 0; i < n_amigos; i++) {
            double l_lim = pos[i] - (vel[i] * mid);
            double r_lim = pos[i] + (vel[i] * mid);

            if (l_lim > l_max) {
                l_max = l_lim;
            }
            if (r_lim < r_max) {
                r_max = r_lim;
            }
        }

        if (l_max <= r_max) {
            r = mid;
        } else {
            l = mid;
        }



    }
    
    cout << fixed << setprecision(12) << r << "\n";

    return 0;
}
