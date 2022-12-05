#include <bits/stdc++.h>
using namespace std;

/** 
 *  Find all DISTINCT permutations of String/Array using recursion.
 *
 *  Time Complexity: O(n!) * O(n) => it is less than this TC because we are skipping duplicates (I don't know exactly)
 *  Space Complexity: O(n!) * O(n)
 */

void permute(int id, vector<int> nums, vector<vector<int>> &ans) {
        if (id==nums.size()) {
            ans.push_back(nums); return;
        }
        
        for (int i=id;i<nums.size();i++) {
            if (i!=id && nums[id]==nums[i]) continue;
            swap(nums[i],nums[id]);
            permute(id+1,nums,ans);
        }
    }

int main() {
    int n;
    cin>>n;

    vector<int> v(n);
    for (auto &i:v) cin>>i;

    vector<vector<int>> permutations;
    permute(0,v,permutations);

    int cnt=1;
    cout<<"Number of Distinct Permutations = "<<permutations.size()<<endl;
    for (auto &i:permutations) {
        cout<<cnt++<<") ";
        for (auto &j:i) cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}