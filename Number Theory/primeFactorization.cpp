#include <bits/stdc++.h>
using namespace std;

template <typename T> vector<T> primeFact(T n) {
    vector<T> primeFacts;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            primeFacts.push_back(d);
            n /= d;
        }
    }

    array<int, 8> inc = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (int d = 7; d * d <= n; d += inc[i++]) {
        while (n % d == 0) {
            primeFacts.push_back(d);
            n /= d;
        }
        i %= 8;
    }

    if (n > 1) primeFacts.push_back(n);
    return primeFacts;
}

int main() {
    int n;
    cin >> n;

    vector<int> p = primeFact(n);

    for (int &i : p) cout << i << " "; cout << endl;

    return 0;
}