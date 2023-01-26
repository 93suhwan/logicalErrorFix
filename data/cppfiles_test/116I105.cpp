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
        int dp1[N + 5], dp2[N + 5];
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        dp1[0] = 1;

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%lld", &x);
            ++x;
            
            dp1[x] += dp1[x];
            dp1[x] += dp1[x - 1];

            dp2[x] += dp2[x];
            dp2[x + 2] += dp2[x + 2];
            if (x > 1) dp2[x] += dp1[x - 2];

        }

        for (int i = 1; i <= N + 1; i++) {
            ans += dp1[i] + dp2[i];
            ans %= mod;
            // printf("%lld %lld\n", dp1[i], dp2[i]);
        }

        printf("%lld\n", ans);
    }
}