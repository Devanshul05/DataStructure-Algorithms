#include <bits/stdc++.h>
using namespace std;
 
struct lazy_node {
    long long n, a, d;

    long long sum() {
        long long an = a + (d * (n - 1));
        return ((a + an) * n) >> 1;
    }
    void merge(lazy_node to_add) {
        a += to_add.a;
        d += to_add.d;
    }
};

struct SegTree {
    vector<long long> seg;
    vector<lazy_node> lazy;
    vector<bool> lazy_status;

    SegTree(int n) {
        seg.resize(4 * n);
        lazy.resize(4 * n);
        lazy_status.resize(4 * n);
        build(0, n - 1, 1);
    }
    long long single(long long x) {
        return x;
    }
    int neutral() {
        return 0;
    }
    long long merge(long long a, long long b) {
        return a + b;
    }

    void build(int l, int r, int i) {
        seg[i] = 0;
        lazy_status[i] = 0;
        lazy[i] = {r - l + 1, 0, 0};
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(l, mid, i << 1);
        build(mid + 1, r, (i << 1) | 1);
    }

    void add(int i, int l, int r, lazy_node to_add) {
        seg[i] += to_add.sum();
        if (l != r) {
            int mid = (l + r) >> 1;
            lazy[i << 1].merge({mid - l + 1, to_add.a, to_add.d});
            lazy_status[i << 1] = 1;
            int diff = (mid + 1) - l, a = to_add.a, d = to_add.d;
            lazy[(i << 1) | 1].merge({r - (mid + 1) + 1, a + (d * diff), d});
            lazy_status[(i << 1) | 1] = 1;
        }
        lazy[i] = {r - l + 1, 0, 0};
        lazy_status[i] = 0;
    }

    void update(int i, int l, int r, int ql, int qr, lazy_node to_add) {
        if (lazy_status[i])
            add(i, l, r, lazy[i]);
        if (l > r || l > qr || r < ql) return;
        if (l >= ql && r <= qr) {
            int diff = l - ql, a = to_add.a, d = to_add.d;
            lazy_node curr = {r - l + 1, a + (d * diff), d};
            add(i, l, r, curr);
            return;
        }
        int mid = (l + r) >> 1;
        update(i << 1, l, mid, ql, qr, to_add);
        update((i << 1) | 1, mid + 1, r, ql, qr, to_add);
        seg[i] = merge(seg[i << 1], seg[(i << 1) | 1]);
    }

    long long query(int l, int r, int ql, int qr, int i) {
        if (lazy_status[i]) add(i, l, r, lazy[i]);
        if (l > r || l > qr || r < ql) return neutral();
        if (l >= ql && r <= qr) return seg[i];
        int mid = (l + r) >> 1;
        return merge(query(l, mid, ql, qr, i << 1), query(mid + 1, r, ql, qr, (i << 1) | 1));
    }
};
 
int main() {
    // https://cses.fi/problemset/task/1736
    int n, q;
    cin >> n >> q;

    SegTree ST(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ST.update(1, 0, n - 1, i, i, {1, x, 0});
    }

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1) {
            ST.update(1, 0, n - 1, l - 1, r - 1, {r - l + 1, 1, 1});
        }
        else {
            cout << ST.query(0, n - 1, l - 1, r - 1, 1) << endl;
        }
    }

    return 0;
}