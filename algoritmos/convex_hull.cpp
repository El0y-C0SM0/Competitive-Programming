#include <bits/stdc++.h>

using namespace std;

/// @brief Retorna se a ordem dos três pontos é horária ou anti-horária
/// @param p1 ponto 1
/// @param p2 ponto 2
/// @param p3 ponto 2
/// @return 
/// positivo se for horária
/// negativo se for anti-horária
/// zero se for colinear
int orientation(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    int x = (p2.second - p1.second) * (p3.first - p2.first)
        - (p2.first - p1.first) * (p3.second - p2.second);

    return x;
}

/// @brief Calcula a distancia ao quadrado entre os pontos p1 e p2
/// @param p1 
/// @param p2 
/// @return distancia ao quadrado
int distPow(pair<int, int> &p1, pair<int, int> &p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + 
                (p1.second - p2.second) * (p1.second - p2.second);
}

/// @brief Convex Hull, algoritmo Grahan Scan
/// @param fig pontos da figura ordenados
/// @param hull pontos do casco convexo
void grahanScan(vector<pair<int, int>> &fig, vector<pair<int, int>> &hull) {
    pair<int, int> p0 = *min_element(fig.begin(), fig.end(), [&](auto &a, auto &b){
        return make_pair(a.second, a.first) < make_pair(b.second, b.first);
    });

    sort(fig.begin(), fig.end(), [&p0](auto &a, auto &b){
        int o = orientation(p0, a, b);

        if(o == 0) 
            return distPow(p0, a) < distPow(p0, b);
        
        return o < 0;
    });
    
    hull.push_back(fig[0]); hull.push_back(fig[1]);
    
    uint k = hull.size();
    for(uint i{2}; fig[0] != fig[i] && i < fig.size(); i++) {
        while (k >= 2 && orientation(hull[k - 2], hull[k - 1], fig[i]) > 0) {
            hull.pop_back();
            k--;
        }
        hull.push_back(fig[i]);
        k++;
    }
}