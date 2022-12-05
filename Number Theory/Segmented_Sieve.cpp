#include <bits/stdc++.h>
using namespace std;

/**
 *  Segmented Sieve for finding primes in a range.
 *  Time Complexity : O((R-L+1).log(log(R)) + sqrt(R).log(log(sqrt(R))))
 */

template <typename T> vector<T> segmentedSieve(T L, T R) {
    T lim = (T)sqrt(R)+1;
    vector<bool> check(lim); 
    vector<T> prime;
    for (T i=2;i<lim;i++) {
        if (!check[i]) {
            prime.push_back(i);
            for (T j=i*i;j<lim;j+=i) {
                check[j]=0;
            }
        }
    }

    vector<T> isPrime(R-L+1,1);
    for (T i:prime) {
        for (T j=max(i*i, (L+i-1)/i*i);j<=R;j+=i) {
            isPrime[j-L]=0;
        }
    }

    if (L==1) isPrime[0]=0;

    return isPrime;
} 

int main() {
    vector<long long> primes = segmentedSieve(2LL, 9LL);

    for (int i=2;i<=9;i++) cout<<i<<" "; cout<<endl;
    for (auto &i:primes) cout<<i<<" "; cout<<endl;

    return 0;
}