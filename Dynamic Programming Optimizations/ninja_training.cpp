#include <bits/stdc++.h>
using namespace std;

/**
 *  Problem Link: https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
 *  TODO: optimize
 */

int dp[100100][3];
int dfs(vector<vector<int>> &v, int n, int id, int last) {
    if (id==n) return 0;

    int ans=0;
    for (int i=0;i<3;i++) {
        if (i!=last) {
            if (dp[id][i]==-1) dp[id][i]=dfs(v,n,id+1,i);
            ans=max(ans,v[id][i]+dp[id][i]);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n;
    memset(dp,-1,sizeof dp);

    vector<vector<int>> v(n,vector<int>(3));
    for (auto &i:v) {
        for (auto &j:i) cin>>j;
    }

    int ans=0;
    for (int i=0;i<3;i++) {
        ans=max(ans,v[0][i]+dfs(v,n,1,i));
    }

    cout<<ans<<endl;

    return 0;
}