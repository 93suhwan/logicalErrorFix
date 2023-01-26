#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
struct modint {
  long long x;
  modint(long long o = 0) { x = o; }
  modint &operator=(long long o) { return x = o, *this; }
  modint &operator+=(modint o) {
    return x = x + o.x >= 1000000007 ? x + o.x - 1000000007 : x + o.x, *this;
  }
  modint &operator-=(modint o) {
    return x = x - o.x < 0 ? x - o.x + 1000000007 : x - o.x, *this;
  }
  modint &operator*=(modint o) { return x = 1ll * x * o.x % 1000000007, *this; }
  modint &operator^=(long long b) {
    modint a = *this, c = 1;
    for (; b; b >>= 1, a *= a)
      if (b & 1) c *= a;
    return x = c.x, *this;
  }
  modint &operator/=(modint o) { return *this *= o ^= 1000000007 - 2; }
  modint &operator+=(long long o) {
    return x = x + o >= 1000000007 ? x + o - 1000000007 : x + o, *this;
  }
  modint &operator-=(long long o) {
    return x = x - o < 0 ? x - o + 1000000007 : x - o, *this;
  }
  modint &operator*=(long long o) {
    return x = 1ll * x * o % 1000000007, *this;
  }
  modint &operator/=(long long o) {
    return *this *= ((modint(o)) ^= 1000000007 - 2);
  }
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
  friend modint operator^(modint a, long long b) { return a ^= b; }
  friend bool operator==(modint a, long long b) { return a.x == b; }
  friend bool operator!=(modint a, long long b) { return a.x != b; }
  bool operator!() { return !x; }
  modint operator-() { return x ? 1000000007 - x : 0; }
};
vector<modint> fac, ifac, iv;
inline void initC(long long n) {
  if (iv.empty()) fac = ifac = iv = vector<modint>(2, 1);
  long long m = iv.size();
  ++n;
  if (m >= n) return;
  iv.resize(n), fac.resize(n), ifac.resize(n);
  for (register long long i = (m); i <= (n - 1); ++i) {
    iv[i] = iv[1000000007 % i] * (1000000007 - 1000000007 / i);
    fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * iv[i];
  }
}
inline modint C(long long n, long long m) {
  if (m < 0 || n < m) return 0;
  return initC(n), fac[n] * ifac[m] * ifac[n - m];
}
inline modint sign(long long n) { return (n & 1) ? (1000000007 - 1) : (1); }
long long n, m, sz[5005];
long long f[5005][5005], a[5005];
long long solve(long long l, long long r) {
  if (l > r) return 0;
  long long p = l;
  for (register long long i = (l + 1); i <= (r); ++i)
    if (a[i] < a[p]) p = i;
  long long ls = solve(l, p - 1), rs = solve(p + 1, r);
  sz[p] = sz[ls] + sz[rs] + 1;
  for (register long long i = (0); i <= (sz[ls]); ++i)
    for (register long long j = (0); j <= (sz[rs]); ++j) {
      f[p][i + j] = max(f[p][i + j], f[ls][i] + f[rs][j] - a[p] * (i * j * 2));
      f[p][i + j + 1] =
          max(f[p][i + j + 1],
              f[ls][i] + f[rs][j] + (m - 2 * (i + 1) * (j + 1) + 1) * a[p]);
    }
  return p;
}
signed main() {
  n = read(), m = read();
  for (register long long i = (1); i <= (n); ++i) a[i] = read();
  cout << f[solve(1, n)][m];
  return 0;
}
