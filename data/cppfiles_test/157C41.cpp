#include <bits/stdc++.h>
using namespace std;
template <int64_t mod>
struct ModInt {
  int64_t x;
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
    x = int64_t(int64_t(1) * x * p.x % mod);
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
    int64_t a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
  ModInt power(int64_t n) const {
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
  static int64_t get_mod() { return mod; }
};
const int64_t mod = 998244353;
using Mint = ModInt<mod>;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int64_t n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k == 0) {
    cout << 1;
    return 0;
  }
  vector<Mint> f(n + 1);
  f[0] = 1;
  for (int64_t i = 1; i <= n; i++) {
    f[i] = f[i - 1] * Mint(i);
  }
  vector<vector<Mint>> choose(2, vector<Mint>(n + 1));
  for (int64_t i : {0, 1}) {
    for (int64_t j = 0; j <= n; j++)
      choose[i][j] = f[j] / (f[k - i] * f[j - (k - i)]);
  }
  vector<int64_t> a;
  for (int64_t i = 0; i < n; i++) {
    if (s[i] == '1') {
      a.push_back(i);
    }
  }
  if (int64_t(a.size()) < k) {
    cout << 1;
    return 0;
  }
  a.insert(a.begin(), -1);
  a.push_back(n);
  Mint ans = 0;
  for (int64_t i = 1; i + k - 1 <= int64_t(a.size()) - 2; i++) {
    int64_t l = a[i], r = a[i + k - 1];
    int64_t L = a[i - 1] + 1, R = a[i + k] - 1;
    ans += choose[0][R - L + 1];
    if (i + k - 1 < int64_t(a.size()) - 2) {
      ans -= choose[1][R - l];
    }
  }
  cout << ans;
  return 0;
}
