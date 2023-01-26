#include <bits/stdc++.h>
using namespace std;
int t, n, a[500500];
long long dp[500500], ter[500500];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; i++) {
      dp[i] = 0;
      ter[i] = 0;
    }
    dp[0]++;
    for (int i = 1; i <= n; i++) {
      dp[a[i] + 1] *= 2;
      dp[a[i] + 1] %= 998244353;
      dp[a[i] + 1] += dp[a[i]];
      dp[a[i] + 1] %= 998244353;
      if (a[i]) {
        ter[a[i] - 1] *= 2;
        ter[a[i] - 1] %= 998244353;
      }
      ter[a[i] + 1] *= 2;
      ter[a[i] + 1] %= 998244353;
      if (a[i] >= 1) {
        ter[a[i] - 1] += dp[a[i] - 1];
        ter[a[i] - 1] %= 998244353;
      }
    }
    long long ans = (998244353 - 1);
    for (int i = 0; i <= n; i++) {
      ans += dp[i];
      ans += ter[i];
      ans %= 998244353;
    }
    printf("%lld\n", ans);
  }
}
