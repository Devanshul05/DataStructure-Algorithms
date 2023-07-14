#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

template <int MOD=1000000007>
struct Modular {
    int value;
    static const int MOD_value = MOD;
    
    Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
    Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}
    
    Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
    Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
    Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}
    
    friend Modular mexp(Modular a, long long e) {
        Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
        return res;
    }
    friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }
    
    Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
    friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
    friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};

using Mint = Modular<MOD>;

const int N = 1001001;
vector<Modular<MOD>> fact(N), invFact(N);
void prefact() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i-1] * i;
        invFact[i] = invFact[i-1] / i;
    }
}

int main() {
    prefact();

    return 0;
}