#include <bits/stdc++.h>
using namespace std;

/**
 *  Frog Jump problem with 'k' range of jump (1 <= jump <= k) at a time.
 * 
 *  Problem Link: https://atcoder.jp/contests/dp/tasks/dp_b
 */

int main() {
    int n,k;
    cin>>n>>k;

    vector<int> v(n),dp(n);
    for (auto &i:v) cin>>i;
    
    for (int i=1;i<n;i++) {
        int minJump=INT_MAX;
        for (int j=1;j<=k;j++) {
            if (i-j>=0) minJump=min(minJump, dp[i-j]+abs(v[i]-v[i-j]));
        }
        dp[i]=minJump;
    }

    cout<<dp[n-1]<<endl;

    return 0;
}