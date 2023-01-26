#include <bits/stdc++.h>
const int MAXN = 2e5;
int n;
int mod, dp[MAXN + 5];
int suf_dp[MAXN + 5];
int main() {
  scanf("%d%d", &n, &mod);
  dp[n] = 1;
  suf_dp[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    (dp[i] += suf_dp[i + 1]) %= mod;
    for (int x = 2; x <= n / i; x++) {
      (dp[i] += (suf_dp[x * i] - suf_dp[std::min(x * (i + 1), n + 1)] + mod) %
                mod) %= mod;
    }
    suf_dp[i] = (dp[i] + suf_dp[i + 1]) % mod;
  }
  printf("%d\n", dp[1]);
  return 0;
}
