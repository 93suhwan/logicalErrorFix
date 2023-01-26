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
    queue<array<int, 4>> q;
    map<array<int, 4>, int> vis;
    array<int, 4> now = {r1, c1, 1, 1};
    vis[now] = 0;
    q.push(now);
    auto ok = [&](int x, int y) { return x == r2 || y == c2; };
    int cycle = 0;
    vector<array<int, 3>> v;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      int x = u[0];
      int y = u[1];
      if (ok(x, y)) v.push_back({x, y, vis[u]});
      int dr = u[2];
      int dc = u[3];
      if (x + dr <= 0 || x + dr > n) dr = -dr;
      if (y + dc <= 0 || y + dc > m) dc = -dc;
      int nx = x + dr;
      int ny = y + dc;
      array<int, 4> t;
      t[0] = nx;
      t[1] = ny;
      t[2] = dr;
      t[3] = dc;
      int d = vis[u] + 1;
      if (vis.count(t) && ok(nx, ny)) {
        cycle = d - vis[t];
        break;
      } else {
        vis[t] = d;
        q.push(t);
        int flag = 0;
        if (nx + dr <= 0 || nx + dr > n) dr = -dr, flag = 1;
        if (ny + dc <= 0 || ny + dc > m) dc = -dc, flag = 1;
        t[0] = nx;
        t[1] = ny;
        t[2] = dr;
        t[3] = dc;
        if (flag == 1 && vis.count(t)) {
          cycle = d - vis[t];
          break;
        } else if (!vis.count(t)) {
          vis[t] = d;
        }
      }
    }
    int c = v.size();
    vector<mint> dp(c);
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
    dp[0] = r * (mint(1) - pre).inv();
    if (c > 1) {
      dp[c - 1] = p2 * (d + dp[0]);
      for (int i = c - 2; i >= 1; i--)
        dp[i] = p2 * (v[i + 1][2] - v[i][2] + dp[i + 1]);
    }
    cout << (v[0][2] + dp[0]).val() << '\n';
  }
  return 0;
}
