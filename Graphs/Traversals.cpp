#include <bits/stdc++.h>
using namespace std;

/**
 * Implementation of Depth-First-Search(DFS) & Breadth-First-Search(BFS) for Graphs.
 */

/*
    Visualization of Graph used below.

       1------3------2
       |    / |      |
       |  /   |      |      7  <=  Notice 7 is not connected to anyone
       |/     4      |
       5        \    |
       |          \  |
        \           \|
         ^-----------6

    Input:
        7 9
        1 3
        1 5
        3 5
        3 4
        3 6
        3 2
        2 6
        4 6
        5 6
*/

vector<bool> vis;
vector<vector<int>> adj;

// Recursive DFS
void dfs1(int vertex) {
    cout<<vertex<<" ";
    vis[vertex]=true;
    for (int &child : adj[vertex]) {
        if (!vis[child]) dfs1(child);
    }
}

// Iterative DFS
void dfs2(int vertex) {
    stack<int> st;
    st.push(vertex);

    while (!st.empty()) {
        int v=st.top();
        st.pop();

        if (vis[v]) continue;

        cout<<v<<" ";
        vis[v]=true;

        for (int &u:adj[v]) {
            if (!vis[u]) st.push(u);
        }
    }
    cout<<endl;
}

// Iterative BFS
void bfs(int vertex) {
    queue<int> q;
    
    q.push(vertex);
    vis[vertex]=true;
    while (!q.empty()) {
        int v=q.front();
        cout<<v<<" ";
        q.pop();

        for (int &u:adj[v]) {
            if (!vis[u]) {
                q.push(u);
                vis[u]=true;
            }
        }
    }
    cout<<endl;
}

int main() {
    int n,m; // n = number of nodes, m = number of egdes
    cin>>n>>m;

    vis.resize(n+1);
    adj.resize(n+1);

    for (int i=0;i<m;i++) {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // We need to run DFS/BFS for every node, because there can be unconnected components aswell.

    cout<<"Recursive DFS: \n";
    int components=0;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            cout<<"Component "<<++components<<": ";
            dfs1(i); cout<<endl;
        }
    }
    cout<<endl;

    cout<<"Iterative DFS: \n";
    fill(vis.begin(),vis.end(),false); // resetting vis for use again
    components=0;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            cout<<"Component "<<++components<<": ";
            dfs2(i);
        }
    }
    cout<<endl;

    cout<<"Iterative BFS: \n";
    fill(vis.begin(),vis.end(),false); // resetting vis for use again
    components=0;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            cout<<"Component "<<++components<<": ";
            bfs(i);
        }
    }
    return 0;
}