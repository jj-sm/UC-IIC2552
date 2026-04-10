#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int s_len;
    cin >> s_len;

    string string_i;
    cin >> string_i;

    char char_count = '1';

    int count_1 = count(string_i.begin(), string_i.end(), char_count);
    
    unsigned short int count_out = 0;

    while (count_1 > 1) {
        if (count_1 % 2 == 1) {
            count_1 = (count_1 / 2) + 1;
        } else {
            count_1 = count_1 / 2;
        }
        count_out += 1;
    }

    cout << count_out << "\n"; 

    return 0;
}
