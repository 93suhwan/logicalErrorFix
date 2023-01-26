#include <bits/stdc++.h>
using namespace std;
int n, m, a[4010], ar[4010], sz, lc[4010], rc[4010], siz[4010];
long long dp[4010][4010];
void DP(const int& x, const int& fa) {
  if (!x) return;
  DP(lc[x], x), DP(rc[x], x), siz[x] = siz[lc[x]] + siz[rc[x]] + 1;
  for (int i = 0; i <= siz[lc[x]]; ++i)
    for (int j = 0; j <= siz[rc[x]] && i + j <= m; ++j) {
      dp[x][i + j] =
          max(dp[x][i + j], dp[lc[x]][i] + dp[rc[x]][j] +
                                1ll * (a[x] - a[fa]) * (m - i - j) * (i + j));
      dp[x][i + j + 1] =
          max(dp[x][i + j + 1],
              dp[lc[x]][i] + dp[rc[x]][j] +
                  1ll * (a[x] - a[fa]) * (m - i - j - 1) * (i + j + 1));
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    while (sz && a[ar[sz]] > a[i]) lc[i] = ar[sz--];
    rc[ar[sz]] = i, ar[++sz] = i;
  }
  for (int i = sz; i > 1; --i) rc[ar[i - 1]] = ar[i];
  a[0] = a[ar[1]], DP(ar[1], 0), printf("%lld", dp[ar[1]][m]);
  return 0;
}
