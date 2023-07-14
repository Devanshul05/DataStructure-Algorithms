#include <bits/stdc++.h>
using namespace std;

// Google KickStart 2022 Round E Problem C

const int N = 101010;
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

vector<Modular<MOD>> pref;
vector<Modular<MOD>> suff;
vector<Modular<MOD>> power;

void StringHash(string &s) {
    int n=(int)s.size();
    pref.resize(n+2);
    suff.resize(n+2);
    power.resize(n+2);

    power[0]=1;
    for (int i=1;i<=n;i++) power[i]=power[i-1]*31;

    // building prefix of string
    for (int i=1;i<=n;i++) {
        int c=s[i-1]-'a'+1;
        pref[i]=c*power[i]+pref[i-1];
    }

    // building suffix of string
    for (int i=n;i>=1;i--) {
        int c=s[i-1]-'a'+1;
        suff[i]=c*power[n-i+1]+suff[i+1];
    }
}

bool pref_palin(int len, int n) {
    Modular<MOD> p1=pref[len];
    Modular<MOD> p2=(suff[1]-suff[len+1]) * mexp(power[n-len],MOD-2);

    return (p1==p2);
}

bool suff_palin(int len, int n) {
    Modular<MOD> p1=suff[len+1];
    Modular<MOD> p2=(pref[n]-pref[len]) * mexp(power[len],MOD-2);

    return (p1==p2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;
    for (int tc=1;tc<=t;tc++) {
        int n; string s;
        cin>>n>>s;
        cout<<"Case #"<<tc<<": ";

        StringHash(s);
        int ans=n;
        for (int i=1;i<=n;i++) {
            if (pref_palin(i,n) && suff_palin(i,n)) {
                ans=i; break;
            }
        }
        cout<<s.substr(0,ans)<<endl;

        pref.clear(); suff.clear(); power.clear();
    }

    return 0;
}