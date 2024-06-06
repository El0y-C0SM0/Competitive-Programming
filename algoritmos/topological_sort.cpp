#include <bits/stdc++.h>

using namespace std;

vector<int> to; // vetor que irá receber os vertices ordenados

/// @brief Realiza a ordenação topológica e salva em to
/// @param i indice do vertice na lista de adjacêcias
/// @param g lista de adjacencias
/// @param vis vetor de visitados
/// @return se foi possivel fazer a ordenação topológica
int dfs(int i, vector<vector<int>> &g, vector<int> &vis) {
    if(vis[i] == -1) return -1;

    if(!vis[i]) {
        vis[i] = -1;
        for(auto j : g[i]) dfs(j, g, vis);
        vis[i] = 1;
        to.push_back(i);
    }
}

/// @brief Realiza a ordenação topológica pelo algoritmo kahn e salva em to
/// @param g lista de adjacencias
/// @param graus vetor com os graus de cada vertice
/// @param vis vetor de visitados
/// @return se foi possivel fazer a ordenação topológica
bool kahn(vector<vector<int>> &g, vector<int> &graus, vector<int> &vis) {
    queue<int> q;

    for(int i{0}; i < static_cast<int>(g.size()); i++) if(!graus[i]) q.push(i);

    while(!q.empty()) {
        int x = q.front(); q.pop();
        to.push_back(x);
        vis[x] = 1;
        
        for(int i : g[x]) if(!vis[i] && --graus[i] == 0)
            q.push(i);
    }

    return to.size() == g.size();
}