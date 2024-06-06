#include <bits/stdc++.h>

using namespace std;

#define ROOT 0 // raiz da dfs

set<int> aps; // conjunto dos pontos de articulação

/// @brief Preenche aps com os pontos
/// @param v vertice inicial
/// @param d distancia de chamada
/// @param g lista de adjacência
/// @param depth vetor com a profundidades dos vertices
/// @param low vetor com os números de descoberta mais baixos
void articulationPoints(int v, int d, vector<vector<int>> &g, vector<int> &depth, vector<int> &low) {
    depth[v] = low[v] = d;

    int children{0};
    for(auto &i : g[v]) {
        if(depth[i] == depth[v] - 1) continue;

        if(depth[i] == -1) {
            articulationPoints(i, d + 1, g, low, depth);
            low[v] = min(low[v], low[i]);

            if(low[i] >= depth[v] && v != ROOT)
                aps.insert(v);

            children++;
        } else low[v] = min(low[v], depth[i]);
    }

    if(v == ROOT && children > 1) aps.insert(v);
}