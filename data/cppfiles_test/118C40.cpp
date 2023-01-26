#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, _G = 3, N = (1 << 21), inv2 = (mod + 1) / 2;
int qpow(int x, int y = mod - 2) {
  int res = 1;
  for (; y; x = (long long)x * x % mod, y >>= 1)
    if (y & 1) res = (long long)res * x % mod;
  return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
  fac[0] = ifac[0] = inv[1] = 1;
  for (int i = (2); i <= (x); ++i)
    inv[i] = (long long)inv[mod % i] * (mod - mod / i) % mod;
  for (int i = (1); i <= (x); ++i)
    fac[i] = (long long)fac[i - 1] * i % mod,
    ifac[i] = (long long)ifac[i - 1] * inv[i] % mod;
}
int C(int x, int y) {
  return y < 0 || x < y ? 0
                        : (long long)fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int rt[N], Lim;
void Pinit(int x) {
  for (Lim = 1; Lim <= x; Lim <<= 1)
    ;
  for (int i = 1; i < Lim; i <<= 1) {
    int sG = qpow(_G, (mod - 1) / (i << 1));
    rt[i] = 1;
    for (int j = (i + 1); j <= (i * 2 - 1); ++j)
      rt[j] = (long long)rt[j - 1] * sG % mod;
  }
}
struct poly {
  vector<int> a;
  int size() { return ((int)(a).size()); }
  int &operator[](int x) { return a[x]; }
  int v(int x) { return x < 0 || x >= ((int)(a).size()) ? 0 : a[x]; }
  void clear() { vector<int>().swap(a); }
  void rs(int x = 0) { a.resize(x); }
  poly(int n = 0) { rs(n); }
  poly(vector<int> o) { a = o; }
  poly(const poly &o) { a = o.a; }
  poly Rs(int x = 0) {
    vector<int> res = a;
    res.resize(x);
    return res;
  }
  inline void dif() {
    int n = ((int)(a).size());
    for (int l = n >> 1; l >= 1; l >>= 1)
      for (int j = 0; j < n; j += l << 1)
        for (int k = 0, *w = rt + l; k < l; k++, w++) {
          int x = a[j + k], y = a[j + k + l];
          a[j + k] = (x + y >= mod ? x + y - mod : x + y);
          a[j + k + l] = (long long)*w * (x < y ? x - y + mod : x - y) % mod;
        }
  }
  void dit() {
    int n = ((int)(a).size());
    for (int i = 2; i <= n; i <<= 1)
      for (int j = 0, l = (i >> 1); j < n; j += i)
        for (int k = 0, *w = rt + l; k < l; k++, w++) {
          int pa = a[j + k], pb = (long long)a[j + k + l] * *w % mod;
          a[j + k] = (pa + pb >= mod ? pa + pb - mod : pa + pb),
                a[j + k + l] = (pa < pb ? pa - pb + mod : pa - pb);
        }
    reverse(a.begin() + 1, a.end());
    for (int i = 0, iv = qpow(n); i < n; i++) a[i] = (long long)a[i] * iv % mod;
  }
  friend poly operator*(poly aa, poly bb) {
    if (!((int)(aa).size()) || !((int)(bb).size())) return {};
    int lim, all = ((int)(aa).size()) + ((int)(bb).size()) - 1;
    for (lim = 1; lim < all; lim <<= 1)
      ;
    aa.rs(lim), bb.rs(lim), aa.dif(), bb.dif();
    for (int i = (0); i <= (lim - 1); ++i)
      aa[i] = (long long)aa[i] * bb[i] % mod;
    aa.dit(), aa.a.resize(all);
    return aa;
  }
  poly Inv() {
    poly res, f, g;
    res.rs(1), res[0] = qpow(a[0]);
    for (int m = 1, pn; m < ((int)(a).size()); m <<= 1) {
      pn = m << 1, f = res, g.rs(pn), f.rs(pn);
      for (int i = 0; i < pn; i++) g[i] = (*this).v(i);
      f.dif(), g.dif();
      for (int i = 0; i < pn; i++) g[i] = (long long)f[i] * g[i] % mod;
      g.dit();
      for (int i = 0; i < m; i++) g[i] = 0;
      g.dif();
      for (int i = 0; i < pn; i++) g[i] = (long long)f[i] * g[i] % mod;
      g.dit(), res.rs(pn);
      for (int i = m; i < min(pn, ((int)(a).size())); i++)
        res[i] = (mod - g[i]) % mod;
    }
    return res.rs(((int)(a).size())), res;
  }
  poly Shift(int x) {
    poly zm(((int)(a).size()) + x);
    for (int i = (0); i <= (((int)(a).size()) - 1); ++i) zm[i + x] = a[i];
    return zm;
  }
  friend poly operator*(poly aa, int bb) {
    poly res(((int)(aa).size()));
    for (int i = (0); i <= (((int)(aa).size()) - 1); ++i)
      res[i] = (long long)aa[i] * bb % mod;
    return res;
  }
  friend poly operator+(poly aa, poly bb) {
    vector<int> res(max(((int)(aa).size()), ((int)(bb).size())));
    for (int i = (0); i <= (((int)(res).size()) - 1); ++i)
      res[i] = (aa.v(i) + bb.v(i) >= mod ? aa.v(i) + bb.v(i) - mod
                                         : aa.v(i) + bb.v(i));
    return poly(res);
  }
  friend poly operator-(poly aa, poly bb) {
    vector<int> res(max(((int)(aa).size()), ((int)(bb).size())));
    for (int i = (0); i <= (((int)(res).size()) - 1); ++i)
      res[i] =
          (aa.v(i) < bb.v(i) ? aa.v(i) - bb.v(i) + mod : aa.v(i) - bb.v(i));
    return poly(res);
  }
  poly &operator+=(poly o) {
    rs(max(((int)(a).size()), ((int)(o).size())));
    for (int i = (0); i <= (((int)(a).size()) - 1); ++i)
      (a[i] += o.v(i)) %= mod;
    return (*this);
  }
  poly &operator-=(poly o) {
    rs(max(((int)(a).size()), ((int)(o).size())));
    for (int i = (0); i <= (((int)(a).size()) - 1); ++i)
      (a[i] += mod - o.v(i)) %= mod;
    return (*this);
  }
  poly &operator*=(poly o) { return (*this) = (*this) * o; }
  poly Integ() {
    if (!((int)(a).size())) return poly();
    poly res(((int)(a).size()) + 1);
    for (int i = (1); i <= (((int)(a).size())); ++i)
      res[i] = (long long)a[i - 1] * inv[i] % mod;
    return res;
  }
  poly Deriv() {
    if (!((int)(a).size())) return poly();
    poly res(((int)(a).size()) - 1);
    for (int i = (1); i <= (((int)(a).size()) - 1); ++i)
      res[i - 1] = (long long)a[i] * i % mod;
    return res;
  }
  poly Ln() {
    poly g = ((*this).Inv() * (*this).Deriv()).Integ();
    return g.rs(((int)(a).size())), g;
  }
  poly Exp() {
    poly res(1), f;
    res[0] = 1;
    for (int m = 1, pn; m < ((int)(a).size()); m <<= 1) {
      pn = min(m << 1, ((int)(a).size())), f.rs(pn), res.rs(pn);
      for (int i = 0; i < pn; i++) f[i] = (*this).v(i);
      f -= res.Ln(), (f[0] += 1) %= mod, res *= f, res.rs(pn);
    }
    return res.rs(((int)(a).size())), res;
  }
  poly pow(int x, int rx = -1) {
    if (rx == -1) rx = x;
    int cnt = 0;
    while (a[cnt] == 0 && cnt < ((int)(a).size())) cnt += 1;
    poly res = (*this);
    for (int i = (cnt); i <= (((int)(a).size()) - 1); ++i)
      res[i - cnt] = res[i];
    for (int i = (((int)(a).size()) - cnt); i <= (((int)(a).size()) - 1); ++i)
      res[i] = 0;
    int c = res[0], w = qpow(res[0]);
    for (int i = (0); i <= (((int)(res).size()) - 1); ++i)
      res[i] = (long long)res[i] * w % mod;
    res = res.Ln();
    for (int i = (0); i <= (((int)(res).size()) - 1); ++i)
      res[i] = (long long)res[i] * x % mod;
    res = res.Exp();
    c = qpow(c, rx);
    for (int i = (0); i <= (((int)(res).size()) - 1); ++i)
      res[i] = (long long)res[i] * c % mod;
    if ((long long)cnt * x > ((int)(a).size()))
      for (int i = (0); i <= (((int)(a).size()) - 1); ++i) res[i] = 0;
    else if (cnt) {
      for (int i = (((int)(a).size()) - cnt * x - 1); i >= (0); --i)
        res[i + cnt * x] = res[i];
      for (int i = (0); i <= (cnt * x - 1); ++i) res[i] = 0;
    }
    return res;
  }
  poly sqrt(int rt = 1) {
    poly res(1), f;
    res[0] = rt;
    for (int m = 1, pn; m < ((int)(a).size()); m <<= 1) {
      pn = min(m << 1, ((int)(a).size())), f.rs(pn);
      for (int i = 0; i < pn; i++) f[i] = (*this).v(i);
      f += res * res, f.rs(pn), res.rs(pn), res = f * res.Inv(), res.rs(pn);
      for (int i = 0; i < pn; i++) res[i] = (long long)res[i] * inv2 % mod;
    }
    return res;
  }
  void Rev() { reverse(a.begin(), a.end()); }
};
int n, deg[N];
poly s[N << 2];
void divide(int x, int L, int R) {
  if (L == R) return s[x] = vector<int>{1, deg[L]}, void();
  int mid = (L + R) >> 1;
  divide(x << 1, L, mid);
  divide(x << 1 | 1, mid + 1, R);
  s[x] = s[x << 1] * s[x << 1 | 1];
}
inline int sign(int x) { return (x & 1) ? mod - 1 : 1; }
int ns;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  init(n << 1), Pinit(n << 1);
  for (int i = (1); i <= (n - 1); ++i) {
    int x, y;
    cin >> x >> y;
    deg[x] += 1;
    deg[y] += 1;
  }
  for (int i = (2); i <= (n); ++i) deg[i] -= 1;
  divide(1, 1, n);
  for (int i = (0); i <= (n - 1); ++i)
    (ns += (long long)fac[n - i] * s[1][i] % mod * sign(i) % mod) %= mod;
  cout << ns << '\n';
  return 0;
}
