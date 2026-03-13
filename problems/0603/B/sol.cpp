#include <iostream>
#include <cstring>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_words;
    cin >> n_words;

    char word[105];

    while (n_words--) {
        cin >> word;
        int len = strlen(word);

        if (len > 10) {
            cout << word[0] << (len - 2) << word[len - 1] << "\n";
        } else {
            cout << word << "\n";
        }
    }
    return 0;
}
