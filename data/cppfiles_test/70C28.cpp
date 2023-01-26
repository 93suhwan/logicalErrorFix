#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5, k = 10, mod = 1e9 + 7;
int n, q, m;
int a[MAXN], sk[MAXN], sum[MAXN];
long long Fstpw(long long a, int b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
int f[MAXN][k + 1], c[k + 1][k + 1], g[MAXN];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    sk[i] = (sk[i - 1] + Fstpw(a[i], k)) % mod;
    sum[i] = (sum[i - 1] + a[i]) % mod;
  }
  for (int i = 0; i <= k; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++)
      f[i + 1][j] = f[i][j] = (f[i][j] + c[k][j] * Fstpw(i, j)) % mod;
    g[i + 1] = g[i] = (g[i] + Fstpw(i, k)) % mod;
  }
  while (q--) {
    int l, r, d;
    scanf("%d%d%d", &l, &r, &d);
    m = r - l + 1;
    int s1 = (sk[r] - sk[l - 1] + mod) % mod,
        a0 = (sum[r] - sum[l - 1] - m * (m - 1ll) / 2 % mod * d % mod +
              mod * 2) %
             mod * Fstpw(m, mod - 2) % mod,
        s2 = 0;
    if (a0) {
      int x1 = d * Fstpw(a0, mod - 2) % mod;
      for (int i = 0, x = 1; i <= k; i++, x = 1ll * x * x1 % mod)
        s2 = (s2 + 1ll * f[m - 1][i] * x) % mod;
      s2 = s2 * Fstpw(a0, k) % mod;
    } else
      s2 = g[m - 1] * Fstpw(d, k) % mod;
    if (s1 == s2)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
