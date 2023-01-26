#include <bits/stdc++.h>
const int maxn = 15, maxk = 1 << maxn, maxt = 2000005, mod = 1000000007;
int n, ans, maxx;
int a[maxn], inv[maxt], bitcnt[maxk], fir[maxt], pfx[maxt];
inline int max(int a, int b) { return a > b ? a : b; }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), maxx = max(maxx, a[i]);
  inv[1] = 1;
  for (int i = 2; i <= 2 * maxx; i++)
    inv[i] = mod - 1ll * inv[mod % i] * (mod / i) % mod;
  for (int i = 1; i < (1 << n); i++) bitcnt[i] = bitcnt[i >> 1] + (i & 1);
  for (int i = 1; i < (1 << n); i++) {
    pfx[i] = 1;
    for (int j = 0; j < n; j++)
      if ((i >> j) & 1)
        for (int k = 0; k < n; k++)
          if (((i >> k) & 1) == 0)
            pfx[i] = 1ll * pfx[i] * a[j] % mod * inv[a[j] + a[k]] % mod;
    fir[i] = pfx[i];
    for (int j = (i - 1) & i; j != 0; j = (j - 1) & i) {
      int p = 1;
      for (int x = 0; x < n; x++)
        if ((j >> x) & 1)
          for (int y = 0; y < n; y++)
            if (((i >> y) & 1) && ((j >> y) & 1) == 0)
              p = 1ll * p * inv[a[x]] % mod * (a[x] + a[y]) % mod;
      fir[i] = (fir[i] - 1ll * fir[j] * pfx[i ^ j] % mod * p % mod + mod) % mod;
    }
  }
  for (int i = 1; i < (1 << n); i++)
    ans = (ans + 1ll * fir[i] * bitcnt[i] % mod) % mod;
  printf("%d\n", ans);
  return 0;
}
