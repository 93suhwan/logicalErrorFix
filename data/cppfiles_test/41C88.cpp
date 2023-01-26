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
    return x = x + o.x >= 998244353 ? x + o.x - 998244353 : x + o.x, *this;
  }
  modint &operator-=(modint o) {
    return x = x - o.x < 0 ? x - o.x + 998244353 : x - o.x, *this;
  }
  modint &operator*=(modint o) { return x = 1ll * x * o.x % 998244353, *this; }
  modint &operator^=(int b) {
    modint a = *this, c = 1;
    for (; b; b >>= 1, a *= a)
      if (b & 1) c *= a;
    return x = c.x, *this;
  }
  modint &operator/=(modint o) { return *this *= o ^= 998244353 - 2; }
  modint &operator+=(int o) {
    return x = x + o >= 998244353 ? x + o - 998244353 : x + o, *this;
  }
  modint &operator-=(int o) {
    return x = x - o < 0 ? x - o + 998244353 : x - o, *this;
  }
  modint &operator*=(int o) { return x = 1ll * x * o % 998244353, *this; }
  modint &operator/=(int o) { return *this *= ((modint(o)) ^= 998244353 - 2); }
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
  modint operator-() { return x ? 998244353 - x : 0; }
};
inline modint qpow(modint x, int y) { return x ^ y; }
vector<modint> fac, ifac, iv;
inline void initC(int n) {
  if (iv.empty()) fac = ifac = iv = vector<modint>(2, 1);
  int m = iv.size();
  ++n;
  if (m >= n) return;
  iv.resize(n), fac.resize(n), ifac.resize(n);
  for (register int i = (m); i <= (n - 1); ++i) {
    iv[i] = iv[998244353 % i] * (998244353 - 998244353 / i);
    fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * iv[i];
  }
}
inline modint C(int n, int m) {
  if (m < 0 || n < m) return 0;
  return initC(n), fac[n] * ifac[m] * ifac[n - m];
}
inline modint sign(int n) { return (n & 1) ? (998244353 - 1) : (1); }
int n, k, col[1000005], pw[1000005];
signed main() {
  n = read(), k = read();
  int t = 0, now = 1;
  while (now < n) now *= k, ++t;
  cout << t << endl;
  pw[0] = 1;
  for (register int i = (1); i <= (t); ++i) pw[i] = pw[i - 1] * k;
  for (register int i = (0); i <= (n - 1); ++i)
    for (register int j = (i + 1); j <= (n - 1); ++j) {
      int c = 0;
      while (i / pw[c] != j / pw[c]) ++c;
      cout << c << " ";
    }
  return 0;
}
