#include <bits/stdc++.h>
using namespace std;
int a[4010], n, m, sta[4010], top, s[4010][2], sz[4010];
long long dp[4010][4010];
void DP(int x) {
  sz[x] = 1;
  for (int i = 0; i < 2; i++) {
    if (s[x][i]) {
      DP(s[x][i]);
      for (int t = min(m, sz[x]); t >= 0; t--)
        for (int j = min(sz[s[x][i]], m); j >= 1; j--)
          dp[x][t + j] = max(dp[x][t] + dp[s[x][i]][j] +
                                 1ll * (a[s[x][i]] - a[x]) * j * (m - j),
                             dp[x][t + j]);
      sz[x] += sz[s[x][i]];
    }
  }
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    while (top && a[sta[top]] > a[i]) s[i][0] = sta[top--];
    if (top) s[sta[top]][1] = i;
    sta[++top] = i;
  }
  int rt = 0;
  for (int i = 1; i <= n; i++)
    if (!rt || a[i] < a[rt]) rt = i;
  DP(rt);
  printf("%lld\n", dp[rt][m]);
}
