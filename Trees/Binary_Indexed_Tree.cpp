#include <bits/stdc++.h>
using namespace std;

// Binary Indexed Tree == Fenwick Tree

template <typename T> struct FenwickTree {
    int n;
    vector<T> bit;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.resize(n + 1);
    }

    FenwickTree(vector<T> v) : FenwickTree(v.size()) {
        for (int i = 0; i < n; i++) add(i, v[i]);
    }

    void add(int i, T val) {
        // for sum
        for (++i ; i < n; i += i & -i) bit[i] += val;

        // for max element
        // for (++i ; i < n; i += i & -i) bit[i] += max(bit[i], val);
    }

    T getSum(int i) {
        T acc = 0;
        for (++i ; i > 0; i -= i & -i) acc += bit[i];
        return acc;
    }

    T getMax(int i) {
        T acc = 0;
        for (++i ; i > 0; i -= i & -i) acc = max(acc, bit[i]);
        return acc;
    }

    T sum(int l, int r) {
        return getSum(r) - getSum(l - 1);
    }
};

int main() {
    

    return 0;
}