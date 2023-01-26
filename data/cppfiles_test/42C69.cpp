#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
struct modint {
  int x;
  modint(int o = 0) { x = o; }
  modint &operator=(int o) { return x = o, *this; }
  modint &operator+=(modint o) {
    return x = x + o.x >= 1000000007 ? x + o.x - 1000000007 : x + o.x, *this;
  }
  modint &operator-=(modint o) {
    return x = x - o.x < 0 ? x - o.x + 1000000007 : x - o.x, *this;
  }
  modint &operator*=(modint o) { return x = 1ll * x * o.x % 1000000007, *this; }
  modint &operator^=(int b) {
    modint a = *this, c = 1;
    for (; b; b >>= 1, a *= a)
      if (b & 1) c *= a;
    return x = c.x, *this;
  }
  modint &operator/=(modint o) { return *this *= o ^= 1000000007 - 2; }
  modint &operator+=(int o) {
    return x = x + o >= 1000000007 ? x + o - 1000000007 : x + o, *this;
  }
  modint &operator-=(int o) {
    return x = x - o < 0 ? x - o + 1000000007 : x - o, *this;
  }
  modint &operator*=(int o) { return x = 1ll * x * o % 1000000007, *this; }
  modint &operator/=(int o) { return *this *= ((modint(o)) ^= 1000000007 - 2); }
  template <class I>
  friend modint operator+(modint a, I b) {
    return a += b;
  }
  template <class I>
  friend modint operator-(modint a, I b) {
    return a -= b;
  }
  template <class I>
  friend modint operator*(modint a, I b) {
    return a *= b;
  }
  template <class I>
  friend modint operator/(modint a, I b) {
    return a /= b;
  }
  friend modint operator^(modint a, int b) { return a ^= b; }
  friend bool operator==(modint a, int b) { return a.x == b; }
  friend bool operator!=(modint a, int b) { return a.x != b; }
  bool operator!() { return !x; }
  modint operator-() { return x ? 1000000007 - x : 0; }
};
vector<modint> fac, ifac, iv;
inline void initC(int n) {
  if (iv.empty()) fac = ifac = iv = vector<modint>(2, 1);
  int m = iv.size();
  ++n;
  if (m >= n) return;
  iv.resize(n), fac.resize(n), ifac.resize(n);
  for (register int i = (m); i <= (n - 1); ++i) {
    iv[i] = iv[1000000007 % i] * (1000000007 - 1000000007 / i);
    fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * iv[i];
  }
}
inline modint C(int n, int m) {
  if (m < 0 || n < m) return 0;
  return initC(n), fac[n] * ifac[m] * ifac[n - m];
}
inline modint sign(int n) { return (n & 1) ? (1000000007 - 1) : (1); }
int n, m, a[400005], b[400005];
int L[400005], ql[400005];
modint tr[400005];
bool vis[400005];
inline void add(int x, modint y) {
  for (; x <= 2 * n; x += x & -x) tr[x] += y;
}
inline modint ask(int x) {
  modint res = 0;
  for (; x; x ^= x & -x) res += tr[x];
  return res;
}
signed main() {
  n = read();
  for (register int i = (1); i <= (n); ++i)
    a[i] = read(), b[i] = read(), L[b[i]] = a[i];
  int Q = read();
  while (Q--) vis[b[read()]] = 1;
  int l = 1;
  modint res = 0;
  for (register int r = (n * 2); r >= (1); --r)
    if (L[r] >= l && vis[r]) ql[r] = l, l = L[r];
  for (register int i = (1); i <= (n * 2); ++i) {
    if (ql[i]) res += ask(ql[i]) + 1;
    if (L[i]) {
      modint now = ask(L[i]) + 1;
      add(1, now), add(L[i] + 1, -now);
    }
  }
  cout << res.x;
  return 0;
}
