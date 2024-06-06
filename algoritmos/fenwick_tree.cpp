#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
    vector<int> v;

    FenwickTree(unsigned int n) {
        n++;
        v = vector<int>(n, 0);
    }

    void insert(unsigned int i, int x) {
        while(i < v.size()) {
            v[i] += x;
            i += i & (-i);
        }
    }

    int sum(unsigned int i) {
        int x{0};

        while(i > 0) {
            x += v[i];
            i -= i & (-i);
        }

        return x;
    }

    int sum(unsigned int i, int j) {
        return sum(j) - sum(i - 1);
    }
};