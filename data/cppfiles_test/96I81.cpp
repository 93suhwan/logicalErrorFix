#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int pwr(int x, int n) {
    if (!n)
        return 1;
    if (n % 2)
        return 1LL * x * pwr(1LL * x * x % MOD, n / 2) % MOD;
    return pwr(1LL * x * x % MOD, n / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n >> x;
    vector comb(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++)
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
    }

    vector dp(n + 1, vector<int>(x + 1));
    for (int i = 1; i <= n; i++)
        for (int j = x; j >= 1; j--) {
            if (i == n)
            dp[i][j] = 1;
            for (int k = i; k <= n; k++)
                if (j + k - 1 <= x)
                    dp[i][j] = (dp[i][j] + 1LL * dp[i][j + k - 1] * comb[k][i] % MOD * pwr(k - 1, k - i)) % MOD;
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int k = i; k >= 0; k--)
            ans = (ans + 1LL * dp[k][i - 1] * comb[i][k] % MOD * pwr(i - k, i - 2)) % MOD;
    cout << ans << '\n';
    return 0;
}
