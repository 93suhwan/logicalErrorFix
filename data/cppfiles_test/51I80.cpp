#include <bits/stdc++.h>
class disjoint_set {
 public:
 protected:
  std::vector<std::size_t> fa;

 public:
  disjoint_set(std::size_t n = 0) : fa(n) {
    std::iota(fa.begin(), fa.end(), 0);
  }
  std::size_t find(std::size_t x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
  }
  bool merge(std::size_t x, std::size_t y) {
    x = find(x), y = find(y);
    if (x == y) {
      return false;
    }
    fa[y] = x;
    return true;
  }
};
std::mt19937 rnd(std::chrono::system_clock().now().time_since_epoch().count());
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> lim(n, n);
  for (int i = 0; i < k; ++i) {
    std::cin >> lim[i];
  }
  std::vector<std::vector<int>> w(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      std::cin >> w[i][j];
      w[j][i] = w[i][j];
    }
  }
  int sum = 0;
  std::vector<std::pair<int, int>> edge;
  int rt = rnd() % (n - k) + k;
  for (int i = 0; i < n; ++i) {
    if (rt != i) {
      edge.emplace_back(rt, i);
      sum += w[rt][i];
    }
  }
  int ans = sum;
  for (double T = 1000000; T >= 1e-5; T *= 0.99996) {
    auto tmp(edge);
    tmp.erase(tmp.begin() + rnd() % (n - 1));
    disjoint_set D(n);
    std::vector<int> deg(n);
    int now = 0;
    for (auto [u, v] : tmp) {
      D.merge(u, v);
      ++deg[u], ++deg[v];
      now += w[u][v];
    }
    int x, y;
    do {
      x = rnd() % n, y = rnd() % n;
    } while (D.find(x) == D.find(y) || deg[x] == lim[x] || deg[y] == lim[y]);
    tmp.emplace_back(x, y);
    now += w[x][y];
    if (exp((sum - now) / T) >= 1.0 * rnd() / rnd.max()) {
      ans = std::min(ans, now);
      edge.swap(tmp);
      sum = now;
    }
  }
  std::cout << ans << "\n";
}
