#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, _G = 3, N = (1 << 20), inv2 = (mod + 1) / 2;
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
  poly pow(int x) {
    poly res = (*this).Ln();
    for (int i = (0); i <= (((int)(res).size()) - 1); ++i)
      res[i] = (long long)res[i] * x % mod;
    res = res.Exp();
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
} s[N];
int n;
int r[N], ns;
void calc(int m) {
  if (m == 0) {
    for (int i = (1); i <= (n); ++i) r[i] = 1;
    ns = 1;
    return;
  }
  int len = m / 2;
  calc(m - len - 1);
  r[1] = len + 1;
  poly s(n + 1), gm(n + 1), all(n + 1);
  for (int i = (1); i <= (n); ++i)
    if (i % 2 == 1) s[i] = r[i], gm[i] = (long long)r[i] * i % mod;
  for (int i = (1); i <= (n); ++i) all[i] = r[i];
  poly cm = (vector<int>{1} - s).Inv();
  poly g = gm * cm, cg = all * all * cm + all * 2;
  for (int i = (1); i <= (n); ++i) r[i] = cg[i];
  if (n % 2)
    ns = 0;
  else
    ns = (long long)ns * 2 % mod;
  (ns += g[n]) %= mod;
  r[1] = m + 1;
}
int m;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  init(n * 5), Pinit(n * 5);
  calc(m - 1);
  cout << ns << "\n";
  return 0;
}
