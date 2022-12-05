#include <bits/stdc++.h>
using namespace std;

/**
 * 0-1 Knapsack Problem
 * Given weights and profits of each item in a room,
 * Your task is to fill a knapsack with maximum profit which can handle the maximum capacity of weight W.
 * You can either pick or not pick an item.
 * 
 * Time Complexity : O(items*cap);
 * @param profit
 * @param weight
 * @param cap
 * @return int
 */

int knapsack(vector<int> profit,vector<int> weight,int cap) {
    int items = weight.size();
    vector<vector<int>> dp(items+1,vector<int>(cap+1));

    for (int i=0;i<=items;i++) {
        for (int w=0;w<=cap;w++) {
            if (i==0 || w==0) dp[i][w] = 0;
            else if (weight[i-1]>w) dp[i][w] = dp[i-1][w];
            else dp[i][w] = max(dp[i-1][w], profit[i-1] + dp[i-1][w-weight[i-1]]);
        }
    }

    return dp[items][cap];
}

int main() {
    vector<int> profit{1, 2, 5, 6};
    vector<int> weight{2, 3, 4, 5};
    int capacity = 8;
    
    cout<<"Profit of Items: ";
    for (auto& i:profit) cout<<i<<" ";
    cout<<'\n';
    
    cout<<"Weight of Items: ";
    for (auto& i:weight) cout<<i<<" ";
    cout<<'\n';

    cout<<"Capacity: "<<capacity<<'\n';
    cout<<"Maximum possible profit for capacity "<<capacity<<": "<<knapsack(profit,weight,capacity)<<'\n';

    return 0;
}