#include <bits/stdc++.h>
using namespace std;
template <long long mod>
struct mint {
  long long x;
  static long long norm(long long x) {
    if (x >= mod + mod || x < -mod) x %= mod;
    if (x > mod) x -= mod;
    if (x < 0) x += mod;
    return x;
  }
  static long long inv(long long a) {
    long long u = 0, v = 1, m = mod;
    while (a != 0) {
      long long t = m / a;
      m -= t * a;
      swap(a, m);
      u -= t * v;
      swap(u, v);
    }
    return norm(u);
  }
  mint() : x(0) {}
  template <typename T>
  mint(T x) : x(norm(x)) {}
  long long operator()() { return x; }
  mint inv() { return mint(inv(x)); }
  mint &operator-=(const mint &rhs) {
    x -= rhs.x;
    if (x < 0) x += mod;
    return *this;
  }
  mint &operator+=(const mint &rhs) {
    x += rhs.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  mint &operator*=(const mint &rhs) {
    x = norm(x * rhs.x);
    return *this;
  }
  mint &operator/=(const mint &rhs) {
    x = norm(x * inv(rhs.x));
    return *this;
  }
  mint &operator++() { return *this += 1; }
  mint &operator--() { return *this -= 1; }
  mint &operator++(int) {
    x += 1;
    return *this;
  }
  mint &operator--(int) {
    x -= 1;
    return *this;
  }
  bool operator<(const mint &rhs) { return x < rhs.x; }
  bool operator==(const mint &rhs) { return x == rhs.x; }
  bool operator!=(const mint &rhs) { return x != rhs.x; }
  friend mint operator/(const mint &lhs, const mint &rhs) {
    return mint(lhs.x * inv(rhs.x));
  }
  friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs.x * rhs.x);
  }
  friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs.x + rhs.x);
  }
  friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs.x - rhs.x);
  }
  friend ostream &operator<<(ostream &os, const mint &rhs) {
    os << rhs.x;
    return os;
  }
  friend istream &operator>>(istream &is, mint &rhs) {
    is >> rhs.x;
    rhs.x = norm(rhs.x);
    return is;
  }
};
const int mod = 1e9 + 7;
using Z = mint<mod>;
Z fpow(Z a, long long b) {
  Z r = 1;
  for (; b; b >>= 1) {
    if (b & 1) r = r * a;
    a = a * a;
  }
  return r;
}
Z comb(int n, int k) {
  if (n < k || k < 0) return 0;
  static vector<Z> f(1, 1), rf(1, 1);
  int p = f.size();
  if (p < n) f.resize(n + 1), rf.resize(n + 1);
  for (int i = p; i <= n; ++i) f[i] = f[i - 1] * i;
  rf[n] = 1 / f[n];
  for (int i = n - 1; i >= p; --i) rf[i] = rf[i + 1] * (i + 1);
  return f[n] * rf[k] * rf[n - k];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<Z> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<vector<Z>> win(n, vector<Z>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      win[i][j] = a[i] * fpow(a[i] + a[j], mod - 2);
    }
  }
  vector<Z> dp(1 << n);
  for (int i = 1; i < 1 << n; ++i) {
    dp[i] = 1;
    for (int j = (i - 1) & i; j; j = (j - 1) & i) {
      Z tmp = 1;
      for (int k = 0; k < n; ++k) {
        if ((i >> k & 1) && (j >> k & 1))
          for (int p = 0; p < n; ++p) {
            if ((i >> p & 1) && !(j >> p & 1)) {
              tmp = tmp * win[k][p];
            }
          }
      }
      dp[i] -= dp[j] * tmp;
    }
  }
  Z ans = 0;
  for (int i = 1; i < 1 << n; ++i) {
    Z tmp = 1;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1)
        for (int k = 0; k < n; ++k) {
          if (!(i >> k & 1)) tmp = tmp * win[j][k];
        }
    }
    ans += tmp * dp[i] * __builtin_popcount(i);
  }
  cout << ans << '\n';
}
