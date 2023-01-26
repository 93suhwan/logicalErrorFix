#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int norm(int x) {
  if (x < 0) x += mod;
  if (x >= mod) x -= mod;
  return x;
}
template <class T>
T power(T a, int b) {
  T res = 1;
  for (; b; b /= 2, a *= a)
    if (b % 2) res *= a;
  return res;
}
template <class T>
T print(T a, int b) {
  T res = 1;
  for (; b; b /= 2, a *= a)
    if (b % 2) res *= a;
  return res;
}
struct mint {
  int x;
  mint(int x = 0) : x(norm(x)) {}
  int val() const { return x; }
  mint operator-() const { return mint(norm(mod - x)); }
  mint inv() const {
    assert(x != 0);
    return power(*this, mod - 2);
  }
  mint &operator*=(const mint &rhs) {
    x = (long long)x * rhs.x % mod;
    return *this;
  }
  mint &operator+=(const mint &rhs) {
    x = norm(x + rhs.x);
    return *this;
  }
  mint &operator-=(const mint &rhs) {
    x = norm(x - rhs.x);
    return *this;
  }
  mint &operator/=(const mint &rhs) { return *this *= rhs.inv(); }
  friend mint operator*(const mint &lhs, const mint &rhs) {
    mint res = lhs;
    res *= rhs;
    return res;
  }
  friend mint operator+(const mint &lhs, const mint &rhs) {
    mint res = lhs;
    res += rhs;
    return res;
  }
  friend mint operator-(const mint &lhs, const mint &rhs) {
    mint res = lhs;
    res -= rhs;
    return res;
  }
  friend mint operator/(const mint &lhs, const mint &rhs) {
    mint res = lhs;
    res /= rhs;
    return res;
  }
};
vector<mint> fac;
vector<mint> inv;
void init(int n) {
  n <<= 1;
  fac.resize(0);
  fac.resize(n + 10, mint(1));
  inv.resize(0);
  inv.resize(n + 10, mint(1));
  for (int i = 2; i <= n; i++) fac[i] = fac[i - 1] * i;
  inv[n] = fac[n].inv();
  for (int i = n - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1);
}
mint C(int n, int m) {
  if (n < 0 || m < 0 || n < m) return mint(0);
  return fac[n] * inv[m] * inv[n - m];
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, r1, c1, r2, c2, p0;
    cin >> n >> m >> r1 >> c1 >> r2 >> c2 >> p0;
    map<array<int, 4>, int> vis;
    auto ok = [&](int x, int y) { return x == r2 || y == c2; };
    int cycle = 0;
    vector<array<int, 3>> v;
    int x = r1;
    int y = c1;
    int dr = 1;
    int dc = 1;
    vis[{x, y, dr, dc}] = 0;
    int now = 0;
    int flag = 0;
    while (true) {
      if (ok(x, y) && flag == 0) v.push_back({x, y, vis[{x, y, dr, dc}]});
      flag = 0;
      if (x + dr <= 0 || x + dr > n) dr = -dr, flag = 1;
      if (y + dc <= 0 || y + dc > m) dc = -dc, flag = 1;
      if (flag == 1) {
        if (vis.count({x, y, dr, dc}) && ok(x, y)) {
          v.pop_back();
          cycle = now - vis[{x, y, dr, dc}];
          break;
        }
        vis[{x, y, dr, dc}] = now;
      } else {
        x += dr;
        y += dc;
        now++;
        if (ok(x, y) && vis.count({x, y, dr, dc})) {
          cycle = now - vis[{x, y, dr, dc}];
          break;
        }
        vis[{x, y, dr, dc}] = now;
      }
    }
    int c = v.size();
    mint dp0;
    mint r = 0;
    mint p = p0;
    mint p2 = mint(1) - p / 100;
    mint pre = 1;
    for (int i = 1; i < c; i++) {
      pre *= p2;
      r += pre * (v[i][2] - v[i - 1][2]);
    }
    int d = v[0][2] + cycle - v.back()[2];
    pre *= p2;
    r += pre * d;
    dp0 = r * (mint(1) - pre).inv();
    cout << (v[0][2] + dp0).val() << '\n';
  }
  return 0;
}
