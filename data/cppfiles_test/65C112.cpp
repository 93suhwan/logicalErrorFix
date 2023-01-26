#include <bits/stdc++.h>
int n, m;
int L[55], R[55], x[55], y[55];
long long f[100005], g[100005];
long long dp[100005], pre[100005];
long long solve(int d) {
  for (int i = 1; i <= n; i++) {
    x[i] = (L[i] - 1) / d + 1;
    y[i] = R[i] / d;
  }
  for (int j = 0; j <= m / d; j++) pre[j] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < x[i]; j++) dp[j] = 0;
    for (int j = x[i]; j <= m / d; j++) {
      dp[j] = pre[j - x[i]];
      if (j > y[i]) dp[j] -= pre[j - y[i] - 1];
      dp[j] %= 998244353;
    }
    pre[0] = dp[0];
    for (int j = 1; j <= m / d; j++) pre[j] = (pre[j - 1] + dp[j]) % 998244353;
  }
  return pre[m / d];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d", &L[i], &R[i]);
  for (int i = 1; i <= m; i++) f[i] = solve(i);
  for (int i = m; i >= 1; i--) {
    g[i] = f[i];
    for (int j = 2 * i; j <= m; j += i) g[i] -= g[j];
    g[i] %= 998244353;
  }
  printf("%lld\n", (g[1] + 998244353) % 998244353);
  return 0;
}
