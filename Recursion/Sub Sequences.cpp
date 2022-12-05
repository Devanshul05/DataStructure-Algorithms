#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int cnt=0;

void subsequences(int i,int n, vector<int> sub) {
    if (i>=n) {
        cout<<"Subsequence "<<++cnt<<": ";
        for (auto &i:sub) cout<<i<<" ";
        cout<<endl;
        return;
    }

    // printing subsequences from end
    /*
    subsequences(i+1,n,sub);
    sub.push_back(v[i]);
    subsequences(i+1,n,sub);
    */

    // printing subsequences from front
    sub.push_back(v[i]);
    subsequences(i+1,n,sub);
    sub.pop_back();
    subsequences(i+1,n,sub);
}

int main() {
    int n; cin>>n;

    v.resize(n);
    for (auto &i:v) cin>>i;

    cout<<endl<<"Total Number of Subsequences: "<<(1<<n)<<endl;
    subsequences(0,n,{});
}