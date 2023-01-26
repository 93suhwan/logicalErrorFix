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
inline long long sub(long long x, long long y) {
  return ((x - y) % 998244353 + 998244353) % 998244353;
}
long long n, rnk;
vector<long long> v[13];
modint sum[13];
void pre(long long d, long long val) {
  ++rnk;
  v[d].push_back(sub(rnk, val));
  if (d == 6) return;
  for (register long long i = (0); i <= (9); ++i) pre(d + 1, val * 10 + i);
}
modint res = 0;
modint calc(long long d, long long coef) {
  long long p =
      lower_bound(v[d].begin(), v[d].end(), 998244353 - coef) - v[d].begin();
  return (coef * v[d].size() % 1000000007 + sum[d] -
          1ll * 998244353 * (v[d].size() - p) % 1000000007);
}
void dfs(long long d, long long val) {
  if (val > n) return;
  if (d >= 1) {
    if (val * 10000000 > n && (val + 1) * 1000000 - 1 <= n) {
      long long pw10 = 1;
      for (register long long i = (0); i <= (6); ++i)
        res += calc(i, sub(rnk, val * pw10)), pw10 *= 10;
      for (register long long i = (0); i <= (6); ++i) rnk += v[i].size();
      return;
    }
    ++rnk;
    res += sub(rnk, val);
  }
  for (register long long i = ((!d)); i <= (9); ++i) dfs(d + 1, val * 10 + i);
}
signed main() {
  n = read();
  pre(0, 0);
  for (register long long d = (0); d <= (6); ++d) {
    sort(v[d].begin(), v[d].end());
    for (auto t : v[d]) sum[d] += t;
  }
  rnk = 0;
  dfs(0, 0);
  cout << res.x;
  return 0;
}
