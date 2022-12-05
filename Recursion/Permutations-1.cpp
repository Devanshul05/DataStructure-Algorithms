#include <bits/stdc++.h>
using namespace std;

/** 
 *  Find all permutations of String/Array using recursion.
 *  
 *  NOTE: Here, we are using an extra vector 'used' to store which element was used, but there is another way to find permutations using in-place swapping
 *  You can refer to permutations2.cpp for it
 *
 *  Time Complexity: O(n!) * O(n)
 *  Space Complexity: O(n!) * O(n) + O(n)
 */

void permute(vector<int> nums, vector<int> v, vector<vector<int>> &ans, vector<bool> used) {
    if (nums.size()==v.size()) {
        ans.push_back(v); return;
    }

    for (int i=0;i<nums.size();i++) {
        if (!used[i]) {
            used[i]=true;
            v.push_back(nums[i]);
            permute(nums,v,ans,used);
            v.pop_back();
            used[i]=false;
        }
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> v(n);
    for (auto &i:v) cin>>i;

    vector<bool> used(n);
    vector<vector<int>> permutations;
    permute(v,{},permutations,used);

    int cnt=1;
    cout<<"Number of Permutations = n! = "<<permutations.size()<<endl;
    for (auto &i:permutations) {
        cout<<cnt++<<") ";
        for (auto &j:i) cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}