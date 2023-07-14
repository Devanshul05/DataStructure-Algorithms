#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;

void checkBipartite() {
    queue<int> q;
    vector<int> side(n, -1);
    bool is_bipartite = true;

    for (int i = 0; i < n; i++) {
        if (side[i] == -1) {
            q.push(i);
            side[i] = 0;
            while (!q.empty()) {
                int v = q.front(); q.pop();
                for (auto u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    }
                    else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }

    if (is_bipartite) {
        cout << "Graph is bipartite and the two sides are:" << endl;
        cout << "1: ";
        for (int i = 0; i < n; i++) {
            if (side[i]) cout << i + 1 << " ";
        }
        cout << endl;

        cout << "2: ";
        for (int i = 0; i < n; i++) {
            if (!side[i]) cout << i + 1 << " ";
        }
        cout << endl;
    }
    else {
        cout << "Graph is not bipartite" <<  endl;
    }

    // return is_bipartite;
}

int main() {
    cin >> n >> m;

    adj.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    checkBipartite();

    return 0;
}