#include <bits/stdc++.h>
using namespace std;
int n, m, sz[4010];
long long dp[4010][4010], a[4010];
int sol(int l, int r) {
  if (l > r) return 0;
  int id = l;
  for (int i = l + 1; i <= r; i++)
    if (a[id] > a[i]) id = i;
  int ls = sol(l, id - 1), rs = sol(id + 1, r);
  sz[id] = sz[ls] + sz[rs] + 1;
  for (int i = 0; i <= sz[ls]; i++)
    for (int j = 0; j <= sz[rs]; j++)
      dp[id][i + j] =
          max(dp[id][i + j], dp[ls][i] + dp[rs][j] - a[id] * i * j * 2);
  for (int i = sz[id]; i; i--)
    dp[id][i] = max(dp[id][i], dp[id][i - 1] + a[id] * (m - 2 * i + 1));
  return id;
}
int main() {
  memset(dp, -0x7f, sizeof(dp));
  dp[0][0] = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  int rt = sol(1, n);
  return printf("%lld", dp[rt][m]), 0;
}
