# DFS

## Recap

### Lista de Adyacencia

Guardamos cada nodo con la lista de nodos que son adyacentes a el.

### BFS

Recorre a lo ancho desde un nodo inicial, y de ahí se puede obtener la distancia mínima.

## DFS

Se busca por profundidad, en caso de encontrar una restricción, se devuelve un nodo donde vuelve a partir hacia otro sin visitar o que no tenga restricción.

- En `c++`

```c++
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edges;
vector<int> visited;

void dfs(int nodo){
    visited[nodo] = 1;
    for (auto u : edges[nodo]) {
        if (visited[u] == 0) {
            dfs(u);
        }
    }
    visited[nodo] = 2;
}

int main(){
    int n, m;
    cin >> n >> m;

    edges.resize(n);
    visited.resize(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; 
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(0);


}
```

Uno de sus usos es en árboles.

DFS se puede hacer con y sin recursión.
