#include <bits/stdc++.h>

using namespace std;

#define int long long

int const mod = 998244353;

main() {
    int T;
    scanf("%lld", &T);

    while (T--) {
        int N;
        scanf("%lld", &N);
        int dp[N + 5];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%lld", &x);
            ++x;

            ans += dp[x] + dp[x - 1];
            dp[x] += dp[x] + dp[x - 1];
            dp[x] %= mod;

            if (x > 1) ans += dp[x - 2];
            ans %= mod;
        }

        printf("%lld\n", ans);
    }
}