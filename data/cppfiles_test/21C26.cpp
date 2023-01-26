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
  ModInt &operator++() { return *this += ModInt(1); }
  ModInt operator++(int) {
    ModInt tmp = *this;
    ++*this;
    return tmp;
  }
  ModInt &operator--() { return *this -= ModInt(1); }
  ModInt operator--(int) {
    ModInt tmp = *this;
    --*this;
    return tmp;
  }
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
long long mpow2(long long x, long long n, long long mod) {
  long long ans = 1;
  while (n != 0) {
    if (n & 1) ans = ans * x % mod;
    x = x * x % mod;
    n = n >> 1;
  }
  return ans;
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
int mod;
struct ModInt2 {
  int x;
  ModInt2() : x(0) {}
  ModInt2(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt2 &operator+=(const ModInt2 &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt2 &operator-=(const ModInt2 &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt2 &operator*=(const ModInt2 &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  ModInt2 &operator/=(const ModInt2 &p) {
    *this *= p.inverse();
    return *this;
  }
  ModInt2 operator-() const { return ModInt2(-x); }
  ModInt2 operator+(const ModInt2 &p) const { return ModInt2(*this) += p; }
  ModInt2 operator-(const ModInt2 &p) const { return ModInt2(*this) -= p; }
  ModInt2 &operator++() { return *this += ModInt2(1); }
  ModInt2 operator++(int) {
    ModInt2 tmp = *this;
    ++*this;
    return tmp;
  }
  ModInt2 &operator--() { return *this -= ModInt2(1); }
  ModInt2 operator--(int) {
    ModInt2 tmp = *this;
    --*this;
    return tmp;
  }
  ModInt2 operator*(const ModInt2 &p) const { return ModInt2(*this) *= p; }
  ModInt2 operator/(const ModInt2 &p) const { return ModInt2(*this) /= p; }
  bool operator==(const ModInt2 &p) const { return x == p.x; }
  bool operator!=(const ModInt2 &p) const { return x != p.x; }
  ModInt2 inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt2(u);
  }
  ModInt2 pow(int64_t n) const {
    ModInt2 ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt2 &p) {
    return os << p.x;
  }
  friend istream &operator>>(istream &is, ModInt2 &a) {
    int64_t t;
    is >> t;
    a = ModInt2(t);
    return (is);
  }
  static int get_mod() { return mod; }
};
using mint = ModInt2;
mint comb[100][100];
map<pair<int, int>, vector<mint>> mp;
vector<mint> solve(const long long n, const long long m, const long long k) {
  if (!mp[{n, m}].empty()) return mp[{n, m}];
  vector<mint> res(k + 1, 0);
  if (n < m) {
    res[0] = 1;
    for (long long i = 1; i < (n + 1); i++) res[0] *= i;
  } else if (m == 1) {
    res[1] = 1;
    for (long long i = 1; i < (n + 1); i++) res[1] *= i;
  } else {
    int lim = min(k, n - m + 1);
    vector<vector<mint>> ret(n);
    for (long long i = 0; i < (n); i++) ret[i] = solve(i, m - 1, k);
    for (long long i = 0; i < (n / 2); i++) {
      mint val = comb[n - 1][i];
      for (long long nk = 0; nk < (lim + 1); nk++)
        for (long long k1 = 0; k1 < (nk + 1); k1++) {
          int k2 = nk - k1;
          res[nk] += ret[i][k1] * ret[n - 1 - i][k2] * val * 2;
        }
    }
    if (n % 2 == 1) {
      for (long long nk = 0; nk < (lim + 1); nk++)
        for (long long k1 = 0; k1 < (nk + 1); k1++) {
          int k2 = nk - k1;
          int i = n / 2;
          res[nk] += ret[i][k1] * ret[n - 1 - i][k2] * comb[n - 1][i];
        }
    }
  }
  mp[{n, m}] = res;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(15);
  long long n, m, k, p;
  cin >> n >> m >> k >> p;
  mod = p;
  for (long long i = 0; i < (100); i++)
    for (long long j = 0; j < (i + 1); j++) {
      comb[i][j] = (j == 0 || j == i ? 1 : comb[i - 1][j - 1] + comb[i - 1][j]);
    }
  cout << solve(n, m, k)[k] << endl;
}
