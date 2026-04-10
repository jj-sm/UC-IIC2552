//
// Created by Juan José Sánchez Medina on 6/03/26.
//

#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    int w;
    cin >> w;

    if (w % 2 == 0 && w > 2) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}