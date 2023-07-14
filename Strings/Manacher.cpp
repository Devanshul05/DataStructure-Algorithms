#include <bits/stdc++.h>
using namespace std;

struct manacher {
    int n;
    vector<int> lp;

    vector<int> initialise(string s) {
        n = s.size();
        s = "$" + s + "^";
        vector<int> p(n + 2);

        // for (auto &i : s) cout << i << " "; cout << endl;

        int l = 1, r = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + (r - i)]));
            
            while (s[i - p[i]] == s[i + p[i]]) p[i]++;

            if (i + p[i] > r) {
                l = i - p[i]; r = i + p[i];
            }
        }

        // for (auto &i : p) cout << i << " "; cout << endl;

        return vector<int>(p.begin() + 1, p.end() - 1);
    }

    void build(string s) {
        string t = "#";
        for (auto &i : s) {
            t.push_back(i);
            t.push_back('#');
        }
        lp = initialise(t);
    }

    int count_palin() {
        int cnt = 0;
        for (int i = 1; i <= n; i++) cnt += lp[i] / 2;
        return cnt;
    }

    int longest_palin(int center, bool odd) {
        return lp[2 * center + 1 + !odd] - 1;
    }

    bool check_palin(int l, int r) {
        return ((r - l + 1) <= longest_palin((l + r) / 2, l % 2 == r % 2));
    }
} m;

int main() {
    string s;
    cin>>s;

    m.build(s);

    /*
        babb a bbab c
             ^
           center
    */
    cout<<m.longest_palin(4, 1)<<endl;
    /*
        | babbab | babc
        ^        ^
        l        r
    */
    cout<<m.check_palin(0, 5)<<endl;

    return 0;
}