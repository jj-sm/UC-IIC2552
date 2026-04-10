#include <iostream>
#include <utility>
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned short int n;
    unsigned short int m;

    cin >> n;
    cin >> m;

    map<string, string> game;

    for (int i = 0; i < n; i++) {
        string name;
        string ip;

        cin >> name;
        cin >> ip;
        
        game[ip] = name;
    }

    for (int i = 0; i < m; i++) {
        string command;
        string ip;

        cin >> command;
        cin >> ip;
        ip.pop_back();

        cout << command << " " << ip << "; #" << game[ip] << "\n";
        
    }



    return 0;
}
