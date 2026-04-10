#include <iostream>
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
    char current;

    for (int i = 0; i < len; i++) {
        cin >> current;

        if (current == prev) {
            count++;        
        } else {
            prev = current;
        }
    }
    
    cout << count << "\n";

    return 0;
}
