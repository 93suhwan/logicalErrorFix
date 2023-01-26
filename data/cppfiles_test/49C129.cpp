#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, a[20], p[20][20], inv[2000010], lb[(1 << 14) + 10], cnt[(1 << 14) + 10],
    f[(1 << 14) + 10], s[20][(1 << 14) + 10], ns[(1 << 14) + 10],
    it[20][(1 << 14) + 10], v[(1 << 14) + 10], sz, ans;
int POW(int x, int y) {
  int ret = 1;
  while (y)
    y& 1 ? ret = 1ll * ret * x % mod : 0, x = 1ll * x * x % mod, y >>= 1;
  return ret;
}
int main() {
  scanf("%d", &n), inv[1] = 1;
  for (int i = 2; i <= 2e6; ++i)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 1; i < (1 << n); ++i)
    lb[i] = (i & 1 ? 1 : lb[i >> 1] + 1), cnt[i] = cnt[i >> 1] + (i & 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    for (int j = 1; j < i; ++j)
      p[i][j] = 1ll * a[i] * inv[a[i] + a[j]] % mod,
      (p[j][i] = (1 - p[i][j] + mod)) >= mod ? p[j][i] -= mod : 0;
  }
  for (int i = 1; i <= n; ++i) {
    s[i][0] = it[i][0] = 1;
    for (int j = 1; j < (1 << n); ++j)
      s[i][j] = 1ll * s[i][j - (j & -j)] * p[i][lb[j]] % mod,
      it[i][j] = 1ll * it[i][j - (j & -j)] * POW(p[lb[j]][i], mod - 2) % mod;
  }
  for (int i = 1; i < (1 << n); ++i) {
    f[i] = 1, sz = 0;
    for (int j = (i - 1 & i); j; j = (j - 1 & i)) v[++sz] = j;
    ns[0] = 1;
    for (int j = sz, t; j >= 1; --j) {
      t = v[j], ns[t] = 1ll * ns[t - (t & -t)] * s[lb[t]][i ^ t] % mod *
                        it[lb[t]][t - (t & -t)] % mod;
      (f[i] += mod - 1ll * f[t] * ns[t] % mod) >= mod ? f[i] -= mod : 0;
    }
  }
  ns[0] = 1;
  for (int i = 1; i < (1 << n); ++i) {
    ns[i] = 1ll * ns[i - (i & -i)] * s[lb[i]][(1 << n) - 1 ^ i] % mod *
            it[lb[i]][i - (i & -i)] % mod;
    ans = (ans + 1ll * f[i] * ns[i] % mod * cnt[i]) % mod;
  }
  printf("%d", ans);
  return 0;
}
