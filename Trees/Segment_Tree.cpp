#include <bits/stdc++.h>
using namespace std;
 
vector<long long> v;
 
class SegTree {
private:
    vector<long long> t;
public:
    SegTree(int n) : t(4 * n) {}

    void build(int i, int tl, int tr) {
        if (tl == tr) {
            t[i] = v[tl]; return;
        }

        int m = (tl + tr) >> 1;
        build(2 * i, tl, m);
        build(2 * i + 1, m + 1, tr);
        t[i] = t[2 * i] + t[2 * i + 1];
    }

    void update(int i, int tl, int tr, int x, int val) {
        if (tl > x || tr < x) return;
        if (tl == tr && tl == x) {
            t[i] = val; return;
        }

        int m = (tl + tr) >> 1;
        update(2 * i, tl, m, x, val);
        update(2 * i + 1, m + 1, tr, x, val);
        t[i] = t[2 * i] + t[2 * i + 1];
    }

    long long sum(int i, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return 0;
        if (tl >= l && tr <= r) return t[i];

        int m = (tl + tr) >> 1;
        return sum(2 * i, tl, m, l, r) + sum(2 * i + 1, m + 1, tr, l, r);
    }
};
 
int main() {
    // https://cses.fi/problemset/task/1646
    int n, m;
    cin>>n>>m;

    v.resize(n);
    for (auto &i:v) cin>>i;

    SegTree ST(n);
    ST.build(1, 0, n - 1);

    for (int i=0;i<m;i++) {
        int l, r;
        cin>>l>>r;

        cout<<ST.sum(1, 0, n-1, l-1, r-1)<<endl;
    }

    return 0;
}