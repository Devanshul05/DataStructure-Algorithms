#include <bits/stdc++.h>
using namespace std;

/**
 *  Standard Frog Jump problem with only 1 or 2 jumps at a time.
 * 
 *  Problem Link: https://atcoder.jp/contests/dp/tasks/dp_a
 */

int main() {
    int n;
    cin>>n;

    vector<int> v(n);
    for (auto &i:v) cin>>i;

    int first=0, second=abs(v[1]-v[0]);
    for (int i=2;i<n;i++) {
        int next=min(second+abs(v[i]-v[i-1]),first+abs(v[i]-v[i-2]));
        first=second; second=next;
    }

    cout<<second<<endl;

    return 0;
}