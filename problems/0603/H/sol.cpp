#include <ios>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */


int digits(int n) {
    if (n == 0) {
        return 1;
    }
    double abs_n = abs(static_cast<double>(n));
    return static_cast<int>(floor(log10(abs_n)) + 1);
}

int suma_rara(int a, int b) {
    vector<int> residuo(15, 0);
    vector<int> resultado(15, 0);

    vector<int> a_vec(15, 0);
    vector<int> b_vec(15, 0);

    for (int i = 0; i < 15; ++i) {
        a_vec[i] = a % 10;
        b_vec[i] = b % 10;
        
        a /= 10;
        b /= 10;

        int sum = a_vec[i] + b_vec[i] + residuo[i];
        
        resultado[i] = sum % 10;
        
        if (i + 2 < 15) {
            residuo[i + 2] += sum / 10;
        }
    }

    int res_final = 0;
    long long multiplier = 1; 
    
    for (int i = 0; i < 15; ++i) {
        res_final += resultado[i] * multiplier;
        multiplier *= 10;
    }

    return res_final;
}


void solve() {
    int num;
    cin >> num;

    int comb = 0;

    for (int a = 1; a <= num; ++a) {
        for (int b = 1; b <= num; ++b) {
            if (suma_rara(a, b) == num) {
                comb++;
            }
        }
    }

    cout << comb << "\n";
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
