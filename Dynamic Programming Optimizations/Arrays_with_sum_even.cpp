#include <bits/stdc++.h>
using namespace std;

/**
 * Count the number of array's that contain N integers in the range L and R inclusively with even sum.
 * 
 * Constraints:
 * 1 <= N <= 10^6
 * 1 <= L <= R <= 10^6
 * 
 * Sample:
 * 1) N = 3, L = 1, R = 2 ==> 4
 * 2) N = 2, L = 1, R = 10 ==> 50
 * 
 * Intended solution is O(N)
 */

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<array<int, 2>> dp(n);

    int even = (r - l + 1) / 2 + (l % 2 == 0 && r % 2 == 0);
    int odd = (r - l + 1) - even;

    dp[0][0] = even;
    dp[0][1] = odd;
    for (int i = 1; i < n; i++) {
        dp[i][0] += even * dp[i-1][0] + odd * dp[i-1][1];
        dp[i][1] += even * dp[i-1][1] + odd * dp[i-1][0];
    }

    cout << dp[n-1][0] << endl;

    return 0;
}