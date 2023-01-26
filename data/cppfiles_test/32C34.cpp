#include <bits/stdc++.h>
using namespace std;
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
template <class T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}
template <class T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}
const int LogN = 20;
int lim, tim, inv[LogN];
vector<int> w[LogN], rev[LogN];
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
  rev[tim].resize(lim), inv[tim] = modpow(lim, -1);
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
  std ::reverse(++f.begin(), f.end());
  for (int i = 0; i < lim; ++i) f[i] = mul(f[i], inv[tim]);
}
const int N = 1e5 + 5;
const int inv2 = modpow(2, -1);
int n, m, a[N], b[N], fac[N];
vector<int> f[N << 2][4], g[2][4];
void solve(int x, int l, int r, bool typ) {
  const int len = r - l + 2;
  for (int o = 0; o < 4; ++o) f[x][o].resize(len);
  if (l == r) return f[x][(b[l] == 1) * 3][1] = 1 + (b[l] != 1), void();
  const int mid = l + r >> 1, lc = x << 1, rc = x << 1 | 1;
  solve(lc, l, mid, 0), solve(rc, mid + 1, r, 1);
  const int ln = mid - l + 2, rn = r - mid + 1;
  for (int o0 = 0; o0 < 4; ++o0)
    for (int o1 = 0; o1 < 4; ++o1) {
      int t0 = (o0 & 1) | (o1 & 2), t2 = (o0 & 2) | (o1 & 1),
          val = (t2 == 3) ? 2 : (t2 == 0 ? inv2 : 1);
      pls(f[x][t0][2], mul(f[lc][o0][1], f[rc][o1][1]));
      pls(f[x][0][1], mul(mul(f[lc][o0][1], f[rc][o1][1]), val));
      for (int i = 3; i <= ln; ++i)
        pls(f[x][t0][i], mul(f[lc][o0][i - 1], f[rc][o1][1]));
      for (int j = 3; j <= rn; ++j)
        pls(f[x][t0][j], mul(f[lc][o0][1], f[rc][o1][j - 1]));
      for (int i = 2; i < ln; ++i)
        pls(f[x][o0 & 1][i], mul(mul(f[lc][o0][i], f[rc][o1][1]), val));
      for (int j = 2; j < rn; ++j)
        pls(f[x][o1 & 2][j], mul(mul(f[lc][o0][1], f[rc][o1][j]), val));
    }
  init_r(len);
  for (int t0 = 0; t0 < 4; ++t0) g[0][t0].resize(lim), g[1][t0].resize(lim);
  for (int o0 = 0; o0 < 4; ++o0)
    f[lc][o0][0] = f[lc][o0][1] = 0, f[lc][o0].resize(lim), ntt(f[lc][o0], 1);
  for (int o1 = 0; o1 < 4; ++o1)
    f[rc][o1][0] = f[rc][o1][1] = 0, f[rc][o1].resize(lim), ntt(f[rc][o1], 1);
  for (int o0 = 0; o0 < 4; ++o0)
    for (int o1 = 0; o1 < 4; ++o1) {
      int t0 = (o0 & 1) | (o1 & 2), t2 = (o0 & 2) | (o1 & 1),
          val = (t2 == 3) ? 2 : (t2 == 0 ? inv2 : 1);
      for (int i = 0; i < lim; ++i)
        g[0][t0][i] = mul(f[lc][o0][i], f[rc][o1][i]);
      ntt(g[0][t0], -1);
      for (int i = 4; i < len; ++i) pls(f[x][t0][i], g[0][t0][i]);
      for (int i = 4; i < len; ++i) pls(f[x][t0][i - 1], mul(g[0][t0][i], val));
    }
}
int main() {
  init_w();
  IN(n);
  for (int i = 1; i <= n; ++i) IN(a[i]);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  bool flag = false;
  for (int l = 1, r; l <= n; l = r + 1) {
    if (r = l + a[l] - 1, r > n) {
      flag = true;
      break;
    }
    for (int i = l; i <= r; ++i)
      if (a[i] != a[l]) flag = true;
    b[++m] = a[l];
  }
  if (flag) return puts("0"), 0;
  solve(1, 1, m, 0);
  int ans = 0;
  for (int i = 1; i <= m; ++i)
    for (int o = 0; o < 4; ++o)
      pls(ans, mul(f[1][o][i], mul(fac[i], ((m - i) & 1) ? mod - 1 : 1)));
  printf("%d\n", ans);
  return 0;
}
