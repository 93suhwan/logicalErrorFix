#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) x += mod;
}
inline void pls(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline int dec(int x, int y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
inline int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline int modpow(int x, long long y, int res = 1) {
  for (y = (y + mod - 1) % (mod - 1); y; y >>= 1, x = mul(x, x))
    if (y & 1) res = mul(x, res);
  return res;
}
char _c;
bool _f;
template <class T>
inline void IN(T &x) {
  x = 0, _f = 0;
  while (_c = getchar(), !isdigit(_c))
    if (_c == '-') _f = 1;
  while (isdigit(_c)) x = x * 10 + _c - '0', _c = getchar();
  if (_f) x = -x;
}
template <class T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}
template <class T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}
const int LogN = 22;
int tim, lim, liminv[LogN];
vector<int> rev[LogN], w[LogN];
inline void init_w(int len = 1 << 19) {
  w[19].resize(len), w[19][0] = 1, w[19][1] = modpow(3, (mod - 1) >> 20);
  for (int i = 2; i < len; ++i) w[19][i] = mul(w[19][i - 1], w[19][1]);
  for (int i = 18; i >= 0; --i) {
    w[i].resize(len >>= 1);
    for (int j = 0; j < len; ++j) w[i][j] = w[i + 1][j << 1];
  }
}
inline void init_r(int len) {
  for (lim = 1, tim = 0; lim < len; lim <<= 1, ++tim)
    ;
  if (rev[tim].size()) return;
  rev[tim].resize(lim), liminv[tim] = modpow(lim, -1);
  for (int i = 0; i < lim; ++i)
    rev[tim][i] = (rev[tim][i >> 1] >> 1) | ((i & 1) << (tim - 1));
}
inline void ntt(vector<int> &f, short typ) {
  static unsigned long long g[1 << 20 | 5];
  for (int i = 0; i < lim; ++i) g[rev[tim][i]] = f[i];
  for (int p = 1, s = 0, t = 0; p < lim; p <<= 1, ++t)
    for (int k = 0; k < lim; k += p << 1)
      for (int l = k; l < k + p; ++l)
        s = mul(g[l + p] % mod, w[t][l - k]), g[l + p] = g[l] + mod - s,
        g[l] += s;
  for (int i = 0; i < lim; ++i) f[i] = g[i] % mod;
  if (~typ) return;
  reverse(++f.begin(), f.end());
  for (int i = 0; i < lim; ++i) f[i] = mul(f[i], liminv[tim]);
}
inline vector<int> polyinv(vector<int> a, int k) {
  vector<int> b(1, modpow(a[0], -1)), c;
  for (int i = 1, l = 2, n = a.size(); i < k; i <<= 1, l <<= 1) {
    init_r(l << 1), c.resize(l);
    for (int j = 0; j < l; ++j) c[j] = j < n ? a[j] : 0;
    c.resize(lim), ntt(c, 1), b.resize(lim), ntt(b, 1);
    for (int j = 0; j < lim; ++j) b[j] = mul(b[j], dec(2, mul(c[j], b[j])));
    ntt(b, -1), b.resize(l);
  }
  return b.resize(k), b;
}
const int N = 5e4 + 5;
int n, m, ans1, ans2;
vector<int> divide(int m) {
  if (m == 1) {
    vector<int> f(n + 1);
    for (int i = 0; i <= n; ++i) f[i] = 1;
    return ans1 = 1, ans2 = 0, f;
  }
  vector<int> f = divide(m - (m + 1) / 2), g(n + 1), h(n + 1);
  if (m & 1) ++f[1];
  for (int i = 0; i <= n; ++i)
    if (!(i & 1)) g[i] = f[i], f[i] = 0;
  for (int i = 0; i <= n; ++i) h[i] = add(i == 0, mod - f[i]);
  h = polyinv(h, n + 1);
  ans2 = mul(2, add(ans2, ans1)), ans1 = 0;
  for (int i = 1; i <= n; ++i)
    if (i & 1) pls(ans1, mul(mul(f[i], i), h[n - i]));
  init_r(n + n + n + 1), g.resize(lim), ntt(g, 1), h.resize(lim), ntt(h, 1);
  for (int i = 0; i < lim; ++i) g[i] = mul(mul(g[i], g[i]), h[i]);
  ntt(g, -1), g.resize(n + 1);
  for (int i = 0; i <= n; ++i) pls(g[i], f[i]);
  return g;
}
int main() {
  init_w(), IN(n), IN(m);
  divide(m), printf("%d\n", add(ans1, mul(!(n & 1), ans2)));
  return 0;
}
