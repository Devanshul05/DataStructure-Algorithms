#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    int comps;
    vector<int> par, rank, sz, mn, mx;
public:
    DSU(int n) : par(n+1), rank(n+1), sz(n+1), mn(n+1), mx(n+1), comps(n) {
        for (int i=1;i<=n;i++) par[i] = i, mn[i] = i, mx[i] = i, sz[i] = 1;
    }

    int find(int v) {
        return (par[v]==v ? v : (par[v] = find(par[v]))); // for path compression
        // return (par[v]==v ? v : find(par[v]));
    }

    bool connected(int u, int v) {
        return (find(u)==find(v));
    }

    int min_in_set(int v) {
        return mn[find(v)];
    }

    int max_in_set(int v) {
        return mx[find(v)];
    }

    int size(int v) {
        return sz[find(v)];
    }

    int component() {
        return comps; // connected components
    }

    int merge(int u, int v) {
        u = find(u); v = find(v);
        if (u==v) return 0;
        else comps--;

        if (rank[u] > rank[v]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
        rank[v] += (rank[u]==rank[v]);
        mn[v] = min(mn[u], mn[v]);
        mx[v] = max(mx[u], mx[v]);
        return v;
    }
};

bool isBipartite(vector<vector<int>>& graph) {
    DSU dsu(graph.size());

    for (int i=0;i<graph.size();i++) {
        for (int j=0;j<graph[i].size();j++) {
            if (dsu.connected(i,graph[i][j])) return false;
            dsu.merge(graph[i][0],graph[i][j]);
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    

    return 0;
}