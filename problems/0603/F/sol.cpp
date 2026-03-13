#include <iostream>
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


void solve() {
    int n;
    cin >> n;
    
    // last_pos guarda el índice de la última vez que vimos cada número.
    // ops guarda cuántas operaciones llevamos contadas para cada número.
    // Usamos índices basados en 1 (de 1 a n).
    vector<int> last_pos(n + 1, 0);
    vector<int> ops(n + 1, 0);
    vector<bool> seen(n + 1, false);
    
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        
        seen[x] = true;
        
        if (last_pos[x] == 0) {
            // Es la primera vez que vemos 'x'. 
            // Si hay números antes que él, requerimos borrar ese prefijo.
            if (i > 1) {
                ops[x]++;
            }
        } else {
            // Ya lo habíamos visto. Si hay un espacio mayor a 1 desde 
            // la última vez, significa que hay otros números en medio.
            if (i - last_pos[x] > 1) {
                ops[x]++;
            }
        }
        // Actualizamos la posición donde acabamos de ver 'x'
        last_pos[x] = i;
    }
    
    int min_ops = n + 1;
    
    for (int x = 1; x <= n; ++x) {
        if (seen[x]) {
            // Si la última aparición de 'x' no fue en el último elemento (n),
            // requerimos una operación extra para borrar el sufijo final.
            if (last_pos[x] < n) {
                ops[x]++;
            }
            min_ops = min(min_ops, ops[x]);
        }
    }
    
    cout << min_ops << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned short int n_cases;
    cin >> n_cases;

    while (n_cases--) {
        solve();
    }

    return 0;
}
