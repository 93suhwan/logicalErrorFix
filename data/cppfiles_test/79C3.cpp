#include <bits/stdc++.h>
constexpr const unsigned int maxn = 300005u;
unsigned int a[maxn], b[maxn];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  unsigned int n;
  std::cin >> n;
  std::vector<unsigned int> a(n + 1), b(n + 1), d(n + 1, -1), bfs(1, n);
  for (unsigned int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  for (unsigned int i = 1; i <= n; ++i) {
    std::cin >> b[i];
  }
  d[n] = 0;
  std::vector<std::pair<unsigned int, unsigned int> > from(n + 1);
  for (unsigned int i = 0, p = n; i != bfs.size(); ++i) {
    unsigned int u = bfs[i];
    if (u <= a[u]) {
      std::cout << d[u] + 1 << '\n';
      if (u != n) {
        std::vector<std::pair<unsigned int, unsigned int> > key(1, from[u]);
        for (; key.back().first != n; key.push_back(from[key.back().first]))
          ;
        std::reverse(key.begin(), key.end());
        for (const auto& uv : key) {
          std::cout << uv.second << ' ';
        }
      }
      std::cout << "0\n";
      return 0;
    }
    for (unsigned int v = u - a[u]; v < p; ++v) {
      unsigned int w = v + b[v];
      if (d[w] == -1u) {
        d[w] = d[u] + 1;
        from[w].first = u;
        from[w].second = v;
        bfs.push_back(w);
      }
    }
    p = std::min(p, u - a[u]);
  }
  std::cout << "-1\n";
  return 0;
}
