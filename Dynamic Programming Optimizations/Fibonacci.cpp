#include <bits/stdc++.h>
using namespace std;

// Calculating Fibonacci series term of index N using DP memiozation

// bottom up
int fib1(int n) {
    vector<int> fib(n);
    if (n==0 || n==1) return 1;
    
    fib[0] = 1;
    fib[1] = 1;
    for (int i=2;i<n;i++) fib[i] = fib[i-1] + fib[i-2];

    return fib[n-1];
}

// top down
vector<int> fibo(1000);
int fib2(int n) {
    if (n==0) return 0;
    if (n==1 || n==2) return 1;
    if (fibo[n]!=0) return fibo[n];

    fibo[n] = fib2(n-1) + fib2(n-2);
    return fibo[n];
}

// using just last two variables
int fib3(int n) {
    int a = 0,b = 1;
    for (int i=2;i<=n;i++) {
        b = a + b;
        a = b - a;
    }
    return (n==0) ? 0 : b;
}

int main() {
    cout<<"Demonstrating fibonacci term calculation: \n";
    cout<<fib1(9)<<" "<<fib2(9)<<" "<<fib3(9)<<endl;

    return 0;
}