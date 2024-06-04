#include <bits/stdc++.h>

#define TAM 100

using namespace std;

int t[TAM][TAM];
unordered_set<int> selecionados;

/// @brief Calcula o maior valor que é possivel obter respeitando o limite de peso
/// @param i numero de items
/// @param W capacidade restante
/// @param pesos vetor de pesos
/// @param valores vetor de obtido
int knapsack(const int n, const int W, vector<int> &pesos, vector<int> &valores) {
    if(t[n][W] != -1) return t[n][W];


    for(int i{0}; i < n; i++) {
        for(int w{0}; w < W; w++) {
            if(!i || !w) t[i][w] = 0;
            else if(t[n][W] != -1) continue;
            else if(pesos[i - 1] <= w) 
                t[i][w] = max(t[i-1][w], valores[i - 1] + t[i-1][w - pesos[i - 1]]);
            else t[i][w] = t[i - 1][w];
        }
    }

    return t[n][W];
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