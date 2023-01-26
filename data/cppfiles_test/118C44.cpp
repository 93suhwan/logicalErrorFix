#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, _G = 3, N = (1 << 20), inv2 = (mod + 1) / 2;
int qpow(int x, int y = mod - 2) {
  int res = 1;
  for (; y; x = (long long)x * x % mod, y >>= 1)
    if (y & 1) res = (long long)res * x % mod;
  return res;
}
int rt[N], mg[N], fac[N], Lim;
void Pinit(int x) {
  for (Lim = 1; Lim <= x; Lim <<= 1)
    ;
  int w = qpow(_G, (mod - 1) / Lim);
  mg[0] = 1;
  for (int i = (1); i <= (Lim - 1); ++i) mg[i] = (long long)mg[i - 1] * w % mod;
  for (int i = 1; i < Lim; i <<= 1) {
    int sG = qpow(_G, mod - 1 - (mod - 1) / (i << 1));
    rt[i] = 1;
    for (int j = (i + 1); j <= (i * 2 - 1); ++j)
      rt[j] = (long long)rt[j - 1] * sG % mod;
  }
}
int rev[N];
void dft(int *a, int n) {
  for (int i = (0); i <= (n - 1); ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
  for (int i = (0); i <= (n - 1); ++i)
    if (i < rev[i]) a[i] ^= a[rev[i]] ^= a[i] ^= a[rev[i]];
  for (int i = 2; i <= n; i <<= 1)
    for (int j = 0, l = (i >> 1); j < n; j += i)
      for (int k = 0, *w = rt + l; k < l; k++, w++) {
        int pa = a[j + k], pb = (long long)a[j + k + l] * *w % mod;
        a[j + k] = (pa + pb >= mod ? pa + pb - mod : pa + pb),
              a[j + k + l] = (pa < pb ? pa - pb + mod : pa - pb);
      }
  for (int i = 0, iv = qpow(n); i < n; i++) a[i] = (long long)a[i] * iv % mod;
}
int n, deg[N], f[N], cnt[N], ns;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n, fac[0] = deg[1] = 1;
  for (int i = (1); i <= (n); ++i) fac[i] = (long long)fac[i - 1] * i % mod;
  for (int i = (1); i <= (n - 1); ++i) {
    int x, y;
    cin >> x >> y;
    deg[x] += 1, deg[y] += 1;
  }
  int all = 0;
  for (int i = (1); i <= (n); ++i)
    if (deg[i] > 1) cnt[deg[i] - 1] += 1, all += 1;
  Pinit(all);
  for (int i = (0); i <= (Lim - 1); ++i) f[i] = 1;
  for (int i = (1); i <= (n); ++i)
    if (cnt[i])
      for (int j = (0); j <= (Lim - 1); ++j)
        f[j] = (long long)f[j] * qpow(mg[j] + i, cnt[i]) % mod;
  dft(f, Lim), reverse(f, f + all + 1);
  for (int i = (0); i <= (n - 1); ++i)
    (ns +=
     (long long)fac[n - i] * f[i] % mod * ((i & 1) ? mod - 1 : 1) % mod) %= mod;
  cout << ns << '\n';
  return 0;
}
