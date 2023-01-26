#include <bits/stdc++.h>
using namespace std;
long long dp[505][505], n, m, jx[505], ny_jx[505], po[505][505],
    ny_po[505][505];
const long long MO = 998244353;
long long pow_(long long x, long long i) {
  if (!i) return 1;
  if (!x) return 0;
  if (i < 0) return pow_(pow_(x, -i), -i);
  long long mid = pow_(x, i >> 1);
  return mid * mid % MO * ((i & 1) ? x : 1) % MO;
}
long long C(long long nn, long long mm) {
  return jx[nn] * ny_jx[mm] % MO * ny_jx[nn - mm] % MO;
}
long long dfs(int nn, int mm) {
  if (~dp[nn][mm]) return dp[nn][mm];
  if (nn > mm) return dp[nn][mm] = (po[mm][nn] - po[mm - 1][nn]) % MO;
  if (!nn) return dp[nn][mm] = 1;
  if (nn == 1) return dp[nn][mm] = 0;
  dp[nn][mm] = 0;
  for (int i = 0; i < nn; i++)
    (dp[nn][mm] +=
     dfs(nn - i, mm - nn + 1) * C(nn, i) % MO * po[nn - 1][i] % MO) %= MO;
  return dp[nn][mm];
}
int main() {
  scanf("%lld%lld", &n, &m);
  memset(dp, -1, sizeof(dp));
  jx[0] = 1;
  for (int i = 1; i <= 500; i++) jx[i] = jx[i - 1] * i % MO;
  ny_jx[500] = pow_(jx[500], MO - 2);
  for (int i = 500 - 1; i >= 0; i--) ny_jx[i] = ny_jx[i + 1] * (i + 1) % MO;
  for (int i = 0; i <= 500; i++)
    for (int j = 0; j <= 500; j++) po[i][j] = pow_(i, j);
  long long ans = 0;
  for (int i = 1; i <= m; i++) (ans += dfs(n, i)) %= MO;
  printf("%lld", (ans + MO) % MO);
  return 0;
}
