#include <bits/stdc++.h>
using i64 = long long;
constexpr int P = 1000000007;
int norm(int x) {
  if (x < 0) {
    x += P;
  }
  if (x >= P) {
    x -= P;
  }
  return x;
}
template <class T>
T power(T a, int b) {
  T res = 1;
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
      res *= a;
    }
  }
  return res;
}
struct Z {
  int x;
  Z(int x = 0) : x(norm(x)) {}
  int val() const { return x; }
  Z operator-() const { return Z(norm(P - x)); }
  Z inv() const {
    assert(x != 0);
    return power(*this, P - 2);
  }
  Z &operator*=(const Z &rhs) {
    x = i64(x) * rhs.x % P;
    return *this;
  }
  Z &operator+=(const Z &rhs) {
    x = norm(x + rhs.x);
    return *this;
  }
  Z &operator-=(const Z &rhs) {
    x = norm(x - rhs.x);
    return *this;
  }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  friend Z operator*(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res *= rhs;
    return res;
  }
  friend Z operator+(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res += rhs;
    return res;
  }
  friend Z operator-(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res -= rhs;
    return res;
  }
  friend Z operator/(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res /= rhs;
    return res;
  }
};
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, std::pair<T, U> v) {
  return os << '(' << v.first << ", " << v.second << ')';
}
template <typename T>
std::ostream &operator<<(std::ostream &os, std::set<T> s) {
  if (s.empty()) return os << "{}";
  os << '{';
  for (auto it = s.begin(); it != prev(s.end()); it++) {
    os << *it << ", ";
  }
  return os << *(prev(s.end())) << '}';
}
template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> v) {
  if (v.empty()) return os << "[]";
  os << '[';
  for (int i = 0; i < v.size() - 1; i++) {
    os << v[i] << ", ";
  }
  return os << v.back() << ']';
}
void Solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> e(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  if (k == 2) {
    std::cout << n * (n - 1) / 2 << '\n';
    return;
  }
  Z ans = 0;
  auto bfs = [&](int s) {
    int cnt = e[s].size();
    if (cnt < k) return;
    std::vector<int> x(cnt), vis(n);
    std::vector<std::vector<int>> g(cnt);
    vis[s] = 1;
    for (int i = 0; i < cnt; i++) {
      g[i].push_back(e[s][i]);
      x[i] = vis[e[s][i]] = 1;
    }
    while (true) {
      std::vector<std::vector<Z>> dp(cnt, std::vector<Z>(k + 1));
      dp[0][0] = dp[0][1] = 1;
      for (int i = 1; i < cnt; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= k; j++) {
          dp[i][j] = dp[i - 1][j] + x[i] * dp[i - 1][j - 1];
        }
      }
      ans += dp[cnt - 1][k];
      fill(x.begin(), x.end(), 0);
      std::vector<int> alive(cnt);
      std::vector<std::vector<int>> newg(cnt);
      for (int i = 0; i < cnt; i++) {
        for (int u : g[i]) {
          for (int v : e[u]) {
            if (!vis[v]) {
              vis[v] = 1;
              newg[i].push_back(v);
              x[i]++;
              alive[i] = 1;
            }
          }
        }
      }
      if (std::accumulate(alive.begin(), alive.end(), 0) < k) {
        break;
      }
      std::swap(g, newg);
    }
  };
  for (int i = 0; i < n; i++) {
    bfs(i);
  }
  std::cout << ans.x << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    Solve();
  }
}
