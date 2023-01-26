#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 13, M = 1e5 + 13, mod = 998244353;
int n, m, prm[M], cnt, mu[M], L[N], R[N], l[N], r[N], f[M], g[M];
bool b[M];
inline void init() {
  mu[1] = 1;
  for (int i = 2; i <= m; ++i) {
    if (!b[i]) prm[++cnt] = i, mu[i] = -1;
    for (int j = 1; j <= cnt && i * prm[j] <= m; ++j) {
      b[i * prm[j]] = 1;
      if (i % prm[j] == 0) break;
      mu[i * prm[j]] = -mu[i];
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &L[i], &R[i]);
  init();
  int ans = 0;
  for (int d = 1; d <= m; ++d) {
    if (!mu[d]) continue;
    for (int i = 1; i <= n; ++i) l[i] = (L[i] - 1) / d + 1, r[i] = R[i] / d;
    int tmp = m / d;
    for (int i = 1; i <= tmp; ++i) f[i] = 0;
    for (int i = l[1]; i <= r[1]; ++i) f[i] = 1;
    for (int i = 1; i <= tmp; ++i) g[i] = (g[i - 1] + f[i]) % mod;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < l[i]; ++j) f[j] = 0;
      for (int j = l[i]; j <= tmp; ++j) {
        f[j] = g[j - l[i]];
        if (j - r[i] - 1 >= 1)
          f[j] -= g[j - r[i] - 1], f[j] = (f[j] % mod + mod) % mod;
      }
      g[0] = 0;
      for (int j = 1; j <= tmp; ++j) g[j] = (g[j - 1] + f[j]) % mod;
    }
    ans += mu[d] * g[tmp] % mod, ans = (ans % mod + mod) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
