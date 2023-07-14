#include <bits/stdc++.h>
using namespace std;

class LCA {
private:
    int n;
    vector<bool> vis;
    vector<int> height, euler, first, t;
public:
    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        vis.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        t.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int v, int h = 0) {
        vis[v] = true;
        height[v] = h;
        first[v] = euler.size();
        euler.push_back(v);
        for (auto u : adj[v]) {
            if (!vis[u]) {
                dfs(adj, u, h + 1);
                euler.push_back(v);
            }
        }
    }

    void build(int i, int tl, int tr) {
        if (tl == tr) {
            t[i] = euler[tl]; return;
        }

        int m = (tl + tr) >> 1;
        build(2 * i, tl, m);
        build(2 * i + 1, m + 1, tr);
        t[i] = min(t[2 * i], t[2 * i + 1]);
    }

    int amin(int i, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return INT_MAX;
        if (tl >= l && tr <= r) return t[i];
 
        int m = (tl + tr) >> 1;
        return min(amin(2 * i, tl, m, l, r), amin(2 * i + 1, m + 1, tr, l, r));
    }

    int lca(int u, int v) {
        int l = first[u], r = first[v];
        if (l > r) swap(l, r);
        return amin(1, 0, euler.size() - 1, l, r);
    }
};

int main() {


    return 0;
}