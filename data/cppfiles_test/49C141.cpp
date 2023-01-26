#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
using namespace std;
template <class T>
using rque = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (b > a) {
    a = b;
    return 1;
  }
  return 0;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  long long cnt = a % b;
  while (cnt != 0) {
    a = b;
    b = cnt;
    cnt = a % b;
  }
  return b;
}
long long extGCD(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extGCD(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
struct UnionFind {
  vector<long long> data;
  int num;
  UnionFind(int sz) {
    data.assign(sz, -1);
    num = sz;
  }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return (false);
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    num--;
    return (true);
  }
  int find(int k) {
    if (data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
  long long size(int k) { return (-data[find(k)]); }
  bool same(int x, int y) { return find(x) == find(y); }
};
template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  static int get_mod() { return mod; }
};
constexpr int mod = 1000000007;
using mint = ModInt<mod>;
mint mpow(mint x, long long n) {
  mint ans = 1;
  while (n != 0) {
    if (n & 1) ans *= x;
    x *= x;
    n = n >> 1;
  }
  return ans;
}
long long mpow2(long long x, long long n, long long mod) {
  long long ans = 1;
  while (n != 0) {
    if (n & 1) ans = ans * x % mod;
    x = x * x % mod;
    n = n >> 1;
  }
  return ans;
}
vector<mint> fac;
vector<mint> ifac;
void setcomb(int sz = 2000010) {
  fac.assign(sz + 1, 0);
  ifac.assign(sz + 1, 0);
  fac[0] = 1;
  for (long long i = 0; i < sz; i++) {
    fac[i + 1] = fac[i] * (i + 1);
  }
  ifac[sz] = fac[sz].inverse();
  for (long long i = sz; i > 0; i--) {
    ifac[i - 1] = ifac[i] * i;
  }
}
mint comb(long long a, long long b) {
  if (fac.size() == 0) setcomb();
  if (a == 0 && b == 0) return 1;
  if (a < b || a < 0 || b < 0) return 0;
  return ifac[a - b] * ifac[b] * fac[a];
}
mint perm(long long a, long long b) {
  if (fac.size() == 0) setcomb();
  if (a == 0 && b == 0) return 1;
  if (a < b || a < 0) return 0;
  return fac[a] * ifac[a - b];
}
long long modinv2(long long a, long long mod) {
  long long b = mod, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= mod;
  if (u < 0) u += mod;
  return u;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(15);
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < (n); i++) cin >> a[i];
  mint p[n][n];
  for (long long i = 0; i < (n); i++)
    for (long long j = 0; j < (n); j++)
      if (i != j) p[i][j] = (mint)a[i] / (a[i] + a[j]);
  mint sum[1 << n][n];
  for (long long i = 0; i < (1 << n); i++)
    for (long long j = 0; j < (n); j++) {
      if (i >> j & 1) continue;
      sum[i][j] = 1;
      for (long long t = 0; t < (n); t++)
        if (i >> t & 1) sum[i][j] *= p[j][t];
    }
  mint dp[1 << n][n];
  for (long long i = 0; i < (1 << n); i++)
    for (long long j = 0; j < (n); j++) {
      if (!(i >> j & 1)) {
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = 1;
      for (long long s = (i - 1) & i; s > 0; s = (s - 1) & i) {
        if (!(s >> j & 1)) continue;
        mint res = dp[s][j];
        for (long long v = 0; v < (n); v++)
          if ((i >> v & 1) && !(s >> v & 1)) res *= sum[s][v];
        dp[i][j] -= res;
      }
    }
  mint ans = 0;
  for (long long i = 0; i < (n); i++) ans += dp[(1 << n) - 1][i];
  cout << ans << endl;
}
