#include <bits/stdc++.h>

#define endl '\n'
#define TAM 100

using namespace std;

int t[TAM][TAM];
unordered_set<int> selecionados;

/// @brief Calcula o maior valor que é possivel obter respeitando o limite de peso
/// @param i indice do item a ser analisado
/// @param cap capacidade restante
/// @param p vetor de pesos
/// @param v vetor de obtido
int knapsack(int i, int cap, vector<int> &p, vector<int> &v) {
    if(cap < 0) return -0x3f3f3f3f;
    if(i == v.size()) return 0;
    if(t[i][cap] > -1) return t[i][cap];

    return t[i][cap] = max(knapsack(i + 1, cap, p, v), knapsack(i + 1, cap - p[i], p, v) + v[i]);
}

/// @brief Recupera os itens que são salvos respeitando o limite de peso
/// @param i indice do item a ser analisado
/// @param cap capacidade restante
/// @param p vetor de pesos
void retrieve(int i, int cap, vector<int> &p, vector<int> &v) {
    if(i == v.size()) return;

    if(cap >= p[i] && knapsack(i + 1, cap, p, v) < knapsack(i + 1, cap - p[i], p, v) + v[i]){
            selecionados.insert(i);
            return retrieve(i + 1, cap - p[i], p, v);
    }

    return retrieve(i + 1, cap, p, v);
}