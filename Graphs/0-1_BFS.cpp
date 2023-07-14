#include <bits/stdc++.h>
using namespace std;

/**
 * Question: Given a weighted graph G with V vertices and E edges, and a constraint on weight of edges W such that W = {0, 1}
 *           Write an efficient algorithm to calculate shortest path from a given source S to all vertices V.
 * 
 * Answer:   Use 0-1 BFS
 * 
 * Souce: https://codeforces.com/blog/entry/22276 <---- Best explanation
 * 
 * Used Input:
        9 12 1
        1 2 0
        1 4 1
        2 3 0
        2 5 1
        3 6 1
        4 5 1
        4 7 0
        5 6 1
        5 8 0
        6 9 1
        7 8 1
        8 9 1

 * Visual Graph:
        A = 1, B = 2, C = 3, ... represent the vertices

        A --- 1 --- B --- 0 --- C
        |           |           |
        1           1           1
        |           |           |
        D --- 1 --- E --- 1 --- F
        |           |           |
        0           0           1
        |           |           |
        G --- 1 --- H --- 1 --- I

 * 
 * @param adj 
 * @param n 
 * @param source 
 * @return vector<int> 
 */

vector<int> BFS01(vector<vector<pair<int,int>>> &adj, int n, int source) {
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    deque<int> dq;
    dq.push_front(source);
    while (!dq.empty()) {
        int v = dq.front();
        dq.pop_front();
        for (auto [u, w] : adj[v]) {
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                if (w) dq.push_back(u);
                else dq.push_front(u);
            }
        }
    }
    return dist;
}

int main() {
    int V, E, S;
    cin >> V >> E >> S;

    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    auto dist = BFS01(adj, V, S);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < V; j++) {
            cout << (i%2 ? dist[j] : j+1) << " ";
        }
        cout << endl;
    }

    return 0;
}