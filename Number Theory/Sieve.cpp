/** SIEVE OF ERATOSTHENES **\
 * Algorithm to find all prime numbers till n.
 * Time Complexity : O(n.log(log(n)))
*/
#include <bits/stdc++.h>
using namespace std;

vector<bool> check;
template <typename T> vector<T> sieve(T n) {
    check.resize(n+2,true);
    check[0]=0; check[1]=0; check[2]=1;
    
    vector<T> prime;
    for (T i=2;i*i<=check.size();i++) {
        if (check[i])
            for (T j=i*i;j<=check.size();j+=i)
                check[j] = 0;
    }

    for (T i=2;i<check.size();i++)
        if (check[i])
            prime.push_back(i);
    
    return prime;
}

int main() {
    vector<long long> primes = sieve((long long)1e5);

    return 0;
}