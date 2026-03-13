#include <iostream>
#include <string>

using namespace std;

/**
 * C++23 Juan Jose Sanchez Medina
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int len;
    cin >> len;

    int count = 0;
    char prev = '\0';

    string frug;
    cin >> frug;

    for (char c: frug) {
        if (c == prev) {
            count++;
        } else {
            prev = c;
        }
    }
    
    cout << count << "\n";

    return 0;
}
