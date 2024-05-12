#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

/// @brief Calcula se é possivel encontar a soma de subconjutos
/// @param p vetor de pesos
/// @param c alvo
/// @return 1 se for possivel encontrar, 0 se não for
bool subset_sum(const vector<int> &p, const int c) {
    int n = p.size();
    if(c < 0) return false;

    vector t(n + 1, vector<char>(c + 1, false));
    
    for(auto &i : t) i[0] = true;

    for(int i{1}; i <= n; i++) {
        for(int j{1}; j <= c; j++) {
            int b = t[i - 1][j];
            if(j >= p[i - 1]) b = t[i - 1][j] || t[i - 1][j - p[i - 1]];
            t[i][j] = b;
        }
    }

    return t[n][c];
}

/// @brief Calcula se é possivel encontar a soma de subconjutos e adciona os valores da soma no conjuto de parametro
/// @param p vetor de pesos
/// @param c alvo
/// @param s conjuto para receber os valores da soma
/// @return 1 se for possivel encontrar, 0 se não for
bool subset_sum(const vector<int> &p, const int c, set<int> &s) {
    int n = p.size();
    if(c < 0) return false;

    vector t(n + 1, vector<char>(c + 1, false));
    
    for(auto &i : t) i[0] = true;

    for(int i{1}; i <= n; i++) {
        for(int j{1}; j <= c; j++) {
            int b = t[i - 1][j];
            if(j >= p[i - 1]) b = t[i - 1][j] || t[i - 1][j - p[i - 1]];
            t[i][j] = b;
        }
    }

    if (!t[n][c]) return t[n][c];

    int m = n, b = c;
    while (m && b) {
        if(t[m][b] != t[m - 1][b]) {
            s.insert(p[m - 1]);
            b -= p[m - 1];
        }

        m--;
    }

    return t[n][c];
}