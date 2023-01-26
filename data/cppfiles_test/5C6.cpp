#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long inv(long long a) {
  long long u = 0, v = 1, b = mod;
  while (a) {
    long long t = b / a;
    b -= t * a, u -= t * v;
    swap(a, b);
    swap(u, v);
  }
  u %= mod;
  if (u < 0) u += mod;
  return u;
}
struct mint {
  int x;
  mint() : x(0) {}
  mint(int x) : x(x) {}
  mint(long long x) : x() {
    if (x >= mod || x < -mod) x %= mod;
    if (x < 0) x += mod;
    this->x = x;
  }
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
    x = (long long)x * rhs.x % mod;
    return *this;
  }
  mint &operator/=(const mint &rhs) {
    x = (long long)x * inv(rhs.x) % mod;
    return *this;
  }
  bool operator<(const mint &rhs) { return x < rhs.x; }
  bool operator==(const mint &rhs) { return x == rhs.x; }
  bool operator!=(const mint &rhs) { return x != rhs.x; }
  mint operator-() { return mint(-x); }
  friend mint operator+(const mint &lhs, const mint &rhs) {
    mint ret(lhs);
    return ret += rhs;
  }
  friend mint operator-(const mint &lhs, const mint &rhs) {
    mint ret(lhs);
    return ret -= rhs;
  }
  friend mint operator*(const mint &lhs, const mint &rhs) {
    mint ret(lhs);
    return ret *= rhs;
  }
  friend mint operator/(const mint &lhs, const mint &rhs) {
    mint ret(lhs);
    return ret /= rhs;
  }
  friend ostream &operator<<(ostream &os, const mint &rhs) {
    os << rhs.x;
    return os;
  }
  friend istream &operator>>(istream &is, mint &rhs) {
    long long a;
    is >> a;
    rhs = a;
    return is;
  }
};
mint fpow(mint a, long long b) {
  mint r = 1;
  for (; b; b >>= 1) {
    if (b & 1) r = r * a;
    a = a * a;
  }
  return r;
}
mint comb(int n, int k) {
  if (n < k || k < 0) return 0;
  static vector<mint> f(1, 1), rf(1, 1);
  if (f.size() <= n) {
    int p = f.size();
    f.resize(n + 1), rf.resize(n + 1);
    for (int i = p; i <= n; ++i) f[i] = f[i - 1] * i;
    rf[n] = 1 / f[n];
    for (int i = n - 1; i >= p; --i) rf[i] = rf[i + 1] * (i + 1);
  }
  return f[n] * rf[k] * rf[n - k];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<mint> f(n + 1);
  for (int i = 1; i < n; ++i)
    f[i + 1] = (f[i] * i * (k - 1) - 1ll * i * k) / (n - i);
  for (int i = 1; i <= n; ++i) f[i] += f[i - 1];
  map<int, int> cnt;
  vector<int> cnt2(n + 1);
  int c = 0;
  for (int i : a) {
    if (i == -1)
      c += 1;
    else
      cnt[i] += 1;
  }
  for (auto [x, y] : cnt) cnt2[y] += 1;
  cnt2[0] += k - cnt.size();
  vector<int> p;
  for (int i = 0; i <= n; ++i)
    if (cnt2[i]) p.push_back(i);
  mint ans = 0;
  for (int j = 0; j <= c; ++j) {
    mint tmp = comb(c, j) * fpow(k - 1, c - j);
    mint sum = 0;
    for (int i : p) sum += cnt2[i] * f[i + j];
    ans += sum * tmp;
  }
  cout << ans / fpow(k, c) - f[n] << endl;
}
