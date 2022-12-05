#include <bits/stdc++.h>
using namespace std;

/** 
 *  Find all permutations of String/Array using recursion.
 * 
 *  This method is optimized as we do not use the extra O(n) vector 'used'
 *
 *  Time Complexity: O(n!) * O(n)
 *  Space Complexity: O(n!) * O(n)
 */

void permute(int id, vector<int> &v, vector<vector<int>> &ans) {
    if (id==v.size()) {
        ans.push_back(v); return;
    }

    for (int i=id;i<v.size();i++) {
        swap(v[i],v[id]);
        permute(id+1,v,ans);
        swap(v[i],v[id]);
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
    cout<<"Number of Permutations = n! = "<<permutations.size()<<endl;
    for (auto &i:permutations) {
        cout<<cnt++<<") ";
        for (auto &j:i) cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}