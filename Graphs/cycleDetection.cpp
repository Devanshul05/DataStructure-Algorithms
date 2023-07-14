#include <bits/stdc++.h>
using namespace std;

/**
 *  Cycle detection using DFS in a undirected graph.
 * 
 *  Time Complexity : O(M), M = No. of edges
 */

int n, m;
vector<int> par;
vector<bool> vis;
vector<vector<int>> adj;
int cycleStart, cycleEnd;

bool dfs(int v, int p) {
    vis[v] = true;
    for (auto u : adj[v]) {
        if (u != p) {
            if (vis[u]) {
                cycleStart = u;
                cycleEnd = v;
                return true;
            }
            par[u] = v;
            if (dfs(u, v)) return true;
        }
    }
    return false;
}

void find_cycle() {
    for (int v = 0; v < n; v++) {
        if (!vis[v] && dfs(v, par[v])) break;
    }

    if (cycleStart == -1) {
        cout << "Acyclic" << endl;
    }
    else {
        vector<int> cycle;
        cycle.push_back(cycleStart);
        for (int v = cycleEnd; v != cycleStart; v = par[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycleStart);

        cout << "Cyclic: ";
        for (auto &v : cycle) {
            cout << v+1 << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;

    cycleStart = -1;
    vis.resize(n);
    adj.resize(n);
    par.assign(n, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_cycle();

    return 0;
}