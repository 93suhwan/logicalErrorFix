#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, mod = 998244353;
int prim[N], nump, mu[N], vis[N], l[N], r[N];
long long f[55][N], sum[N];
int n, m;
void init() {
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      prim[++nump] = i;
      mu[i] = -1;
    }
    for (int j = 1; j <= nump && i * prim[j] <= n; j++) {
      vis[i * prim[j]] = 1;
      if (i % prim[j] == 0)
        break;
      else
        mu[i * prim[j]] = -mu[i];
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  init();
  for (int i = 1; i <= n; i++) scanf("%d%d", l + i, r + i);
  long long ans = 0;
  for (int d = 1; d <= m; d++) {
    f[0][0] = 1;
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
      sum[0] = f[i - 1][0];
      for (int j = 1; j <= m / d; j++) sum[j] = sum[j - 1] + f[i - 1][j];
      for (int j = (l[i] + d - 1) / d; j <= m / d; j++) {
        if (j <= r[i] / d)
          f[i][j] = sum[j - (l[i] + d - 1) / d];
        else
          f[i][j] = sum[j - (l[i] + d - 1) / d] - sum[j - r[i] / d - 1];
        f[i][j] %= mod;
      }
    }
    for (int j = 1; j <= m / d; j++) cnt += f[n][j];
    ans += cnt * mu[d];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
