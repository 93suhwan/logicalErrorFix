#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m, i, j, k;
int dp[1010], ans, a[1010];
signed main() {
  memset(dp, 0x3f, sizeof(dp));
  n = read();
  m = dp[0];
  dp[0] = 0;
  for (i = 1; i <= n; ++i) {
    a[i] = read();
    for (j = 0; j <= 512; ++j)
      if (dp[j] != m && a[i] > dp[j]) dp[j ^ a[i]] = min(dp[j ^ a[i]], a[i]);
  }
  for (i = k = 0; i <= 512; ++i)
    if (dp[i] != m) ++ans;
  printf("%d\n", ans);
  for (i = 0; i <= 512; ++i)
    if (dp[i] != m) printf("%d ", i);
  return 0;
}
