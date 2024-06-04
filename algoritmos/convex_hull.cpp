#include <bits/stdc++.h>

using namespace std;

/// @brief Convex Hull, algoritmo Grahan Scan
/// @param fig pontos da figura ordenados
/// @param cvx pontos do casco convexo
void grahan_scan(vector<pair<int, int>> &fig, stack<pair<int, int>> &cvx) {
    cvx.push(fig[0]); cvx.push(fig[1]);
    
    for(uint i{2}; fig[0] != fig[i] && i < fig.size() - 1; i++) {
        while (cvx.size() >= 2 && atan2(fig[i].second - cvx.top().second, fig[i].first - cvx.top().first) >= 1) 
            cvx.pop();
        cvx.push(fig[i]);
    }
}