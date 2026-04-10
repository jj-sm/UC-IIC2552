#include <iostream>
#include <system_error>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

/**
 * C++23 CP Template
 * Compile with: g++ -std=c++23 -O2
 */


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<vector<char>> mapa(n, vector<char>(m));

    int start_coord_i, start_coord_j;
    int end_coord_i, end_coord_j;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char value;
            cin >> value;
            
            mapa[i][j] = value;

            if (value == 'A') {
                start_coord_i = i;
                start_coord_j = j;
            }
            if (value == 'B') {
                end_coord_i = i;
                end_coord_j = j;
            }
        }
    }

    struct Node {
        int r, c, dist;
    };

    queue<Node> q;
    q.push({start_coord_i, start_coord_j, 0});

    vector<vector<bool>> visitados(n, vector<bool>(m, false));

    int fila_mov[] = {-1, 1, 0, 0};
    int col_mov[] = {0, 0, -1, 1};

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (mapa[curr.r][curr.c] == 'B') {
            cout << curr.dist << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int next_i = curr.r + fila_mov[i];
            int next_j = curr.c + col_mov[i];

            if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m && mapa[next_i][next_j] != '#' && !visitados[next_i][next_j]) {
                
                visitados[next_i][next_j] = true;
                q.push({next_i, next_j, curr.dist + 1});
            }
        }
    }

    cout << "-1" << "\n";
    return 0;
}

