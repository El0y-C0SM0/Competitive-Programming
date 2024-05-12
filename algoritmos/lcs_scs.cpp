#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

/// @brief Retorna a maior subsequencia entre as strings s1 e s2
/// @param s1 
/// @param s2 
/// @return maior subsequencia entre s1 e s2
string lcs(string &s1, string &s2) {
    vector t(s1.size() + 1, vector<int>(s2.size() + 1, 0));

    for(int i = s1.size() - 1; i >= 0; i--) {
        for(int j = s2.size() - 1; j >= 0; j--) {
            if(s1[i] == s2[j]) t[i][j] = t[i + 1][j + 1] + 1;
            else t[i][j] = max(t[i + 1][j], t[i][j + 1]); 
        }
    }

    string s;
    int i = 0, j = 0;

    while(i < s1.size() && j < s2.size()) {
        if(s1[i] == s2[j]) {
            s.push_back(s1[i]);
            i++; j++;
        } else if(t[i + 1][j] >= t[i][j + 1]) i++;
        else j++;
    }

    return s;
}

/// @brief Retorna a menor supersequencia entre as strings s1 e s2
/// @param s1 
/// @param s2 
/// @return menor supersequencia entre s1 e s2
string scs(string &s1, string &s2) {
    int m = s1.size(), n = s2.size();
    vector t(m + 1, vector<int>(n + 1, 0));

    for(int i{0}; i <= m; i++) {
        for(int j{0}; j <= n; j++) {
            if(!i) t[0][j] = j;
            else if(!j) t[i][0] = i;
            else if(s1[i - 1] == s2[j - 1]) t[i][j] = 1 + t[i - 1][j - 1];
            else t[i][j] = 1 + min(t[i - 1][j], t[i][j - 1]);
        }
    }

    string s = "";
    int len = t[m][n], i = m, j = n;

    while(len--) {
        if(i && j && s1[i - 1] == s2[j - 1]) {
            s += s1[i - 1];
            i--; j--;
        } else if(j && t[i][j] - 1 == t[i][j - 1]) {
            s += s2[j - 1];
            j--;
        } else if(i) {
            s += s1[i - 1];
            i--;
        }
    }

    reverse(s.begin(), s.end());

    return s;
}