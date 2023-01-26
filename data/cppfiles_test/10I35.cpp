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
int main() {
  int n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long p = 1ll * n * m - 1ll * r * c;
  cout << fpow(k, p) << endl;
}
