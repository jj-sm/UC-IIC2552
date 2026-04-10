#include <iostream>
#include <map>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, pair<int, pair<int, int>>> ducks;

    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        ducks[i].first = price;     
    }

    for (int i = 0; i < n; i++) {
        int color_duck;
        cin >> color_duck;
        ducks[i].second.first = color_duck;
    }

    for (int i = 0; i < n; i++) {
        int color_hat;
        cin >> color_hat;
        ducks[i].second.second = color_hat;
    }

    int n_buyers;
    cin >> n_buyers;

    for (int i = 0; i < n_buyers; i++) {
        int favourite_color;
        bool check = false;
        int cheapest = 1e9;
        int cheapest_idx = -1;
        cin >> favourite_color;

        for (auto it = ducks.begin(); it != ducks.end(); ) {
           if (it->second.second.first == favourite_color || it->second.second.second == favourite_color) {
                // cout << it->second.first << " ";                
                // it = ducks.erase(it); 
                // check = true;
                // break;
                int price = it->second.first;
                if (price <= cheapest) {
                    cheapest_idx = it->first;
                    cheapest = price;
                }

           }
           it++;
        }
        
        if (cheapest_idx != -1) {
            cout << cheapest << " ";
            ducks.erase(cheapest_idx);
            check = true;
        }


        if (check == false) {
            cout << "-1 ";
        }
    }





    return 0;
}

