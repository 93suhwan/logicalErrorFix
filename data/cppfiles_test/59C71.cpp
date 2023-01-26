#include <bits/stdc++.h>
namespace {
using LL = long long;
struct Solver {
  int n, m;
  std::vector<int> a, b;
  std::vector<std::vector<int>> graph;
  LL cur = 0;
  std::vector<char> cycle, instack;
  bool dfs(int u, int prev) {
    if (cycle[u] || instack[u]) return true;
    if (cur <= a[u]) return false;
    instack[u] = true;
    cur += b[u];
    for (int v : graph[u])
      if (v != prev) {
        if (dfs(v, u)) {
          cycle[u] = true;
          instack[u] = false;
          return true;
        }
      }
    cur -= b[u];
    instack[u] = false;
    return false;
  }
  bool ok(int start) {
    cur = start;
    std::fill(cycle.begin(), cycle.end(), false);
    cycle[0] = true;
    auto aug = [&]() -> bool {
      for (int u = 0; u < n; ++u)
        if (cycle[u]) {
          for (int v : graph[u])
            if (!cycle[v]) {
              if (dfs(v, u)) return true;
            }
        }
      return false;
    };
    while (aug())
      ;
    return std::count(cycle.begin(), cycle.end(), true) == n;
  }
  void solve(int ca, std::istream& reader) {
    reader >> n >> m;
    a.resize(n);
    b.resize(n);
    for (int i = 1; i < n; ++i) {
      reader >> a[i];
    }
    for (int i = 1; i < n; ++i) {
      reader >> b[i];
    }
    graph.resize(n);
    for (int i = 0; i < m; ++i) {
      int x, y;
      reader >> x >> y;
      --x;
      --y;
      graph[x].emplace_back(y);
      graph[y].emplace_back(x);
    }
    cycle.resize(n);
    instack.resize(n);
    int l = 0, r = 1e9 + 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok(mid))
        r = mid - 1;
      else
        l = mid + 1;
    }
    printf("%d\n", r + 1);
  }
};
}  // namespace
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;
  int cas = 1;
  reader >> cas;
  for (int ca = 1; ca <= cas; ++ca) {
    Solver().solve(ca, reader);
  }
}
