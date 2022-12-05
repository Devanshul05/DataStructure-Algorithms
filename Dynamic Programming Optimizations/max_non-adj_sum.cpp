#include <bits/stdc++.h>
using namespace std;

/**
 *  Pick sequence of non-adjacent elements whose sum is maximum.
 * 
 *  Problem Link: https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261
 */

int main() {
    int n;
    cin>>n;

    vector<int> v(n),dp(n);
    for (auto &i:v) cin>>i;

    dp[0]=v[0];
    for (int i=1;i<n;i++) {
        dp[i]=max(dp[i-1],(i>1 ? dp[i-2] : 0)+v[i]);
    }

    cout<<dp[n-1]<<endl;
}