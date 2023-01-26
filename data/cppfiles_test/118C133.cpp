#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 19, mod = 998244353, G = 3, Gi = 332748118;
int n, ans, lim, L, fac[N], kids[N], R[N];
inline int qpow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = (long long)a * a % mod)
    if (b & 1) ans = (long long)ans * a % mod;
  return ans;
}
inline void NTT(vector<int> &f, int type) {
  for (int i = 0; i < lim; ++i)
    if (i < R[i]) swap(f[i], f[R[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    int Wn = qpow(type == 1 ? G : Gi, (mod - 1) / (mid << 1));
    for (int j = 0; j < lim; j += (mid << 1))
      for (int k = 0, w = 1; k < mid; ++k, w = (long long)w * Wn % mod) {
        int x = f[j + k], y = (long long)w * f[j + k + mid] % mod;
        f[j + k] = (x + y) % mod, f[j + k + mid] = (x - y + mod) % mod;
      }
  }
  if (type == 1) return;
  int inv = qpow(lim, mod - 2);
  for (int i = 0; i < lim; ++i) f[i] = (long long)f[i] * inv % mod;
}
inline vector<int> solve(int l, int r) {
  if (l == r) return {1, kids[l]};
  int mid = l + r >> 1;
  vector<int> f = solve(l, mid), g = solve(mid + 1, r);
  lim = 1, L = 0;
  while (lim <= r - l + 1) lim <<= 1, ++L;
  for (int i = 0; i < lim; ++i) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
  f.resize(lim), g.resize(lim), NTT(f, 1), NTT(g, 1);
  for (int i = 0; i < lim; ++i) f[i] = (long long)f[i] * g[i] % mod;
  return NTT(f, -1), f;
}
int main() {
  scanf("%d", &n), fac[0] = fac[1] = 1;
  for (int i = 2; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    ++kids[x], ++kids[y], --kids[i];
    fac[i] = (long long)fac[i - 1] * i % mod;
  }
  vector<int> F = solve(1, n);
  for (int i = 0; i < n; ++i)
    if (i & 1)
      (ans += mod - (long long)fac[n - i] * F[i] % mod) %= mod;
    else
      (ans += (long long)fac[n - i] * F[i] % mod) %= mod;
  return printf("%d\n", ans), 0;
}
