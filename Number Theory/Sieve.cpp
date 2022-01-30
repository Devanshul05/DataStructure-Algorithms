/** SIEVE OF ERATOSTHENES **\
 * Algorithm to find all prime numbers till n.
 * Time Complexity : O(n.log(log(n)))
*/
#include <bits/stdc++.h>
using namespace std;

void sieve(int n) {
    vector<int> primes(n+1,1);
    for (int i=2;i*i<=n;i++) {
        if (primes[i]) {
            for (int j=i*i;j<=n;j+=i) {
                primes[j] = 0;
            }
        }
    }

    for (int i=2;i<=n;i++) {
        if (primes[i]) {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main() {
    int n = 30;
    sieve(n);

    return 0;
}