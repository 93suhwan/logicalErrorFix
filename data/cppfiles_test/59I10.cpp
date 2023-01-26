#include <bits/stdc++.h>
using LL = long long;
struct Solver {
  int n, m;
  std::vector<int> a, b;
  std::vector<std::vector<int>> graph;
  bool judge(LL pw) {
    std::vector<int> cycle(n);
    cycle[0] = true;
    int cnt = 1;
    auto aug = [&]() -> bool {
      std::vector<int> prev(n, -1);
      std::vector<LL> pws(n, 0);
      for (int u = 0; u < n; ++u)
        if (cycle[u]) {
          std::queue<int> que;
          que.emplace(u);
          pws[u] = pw;
          while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int w : graph[v])
              if (!cycle[w] && prev[w] == -1 && pws[v] > a[w]) {
                prev[w] = v;
                pws[w] = pws[v] + b[w];
                que.emplace(w);
              }
          }
        }
      for (int u = 0; u < n; ++u)
        if (cycle[u] || prev[u] != -1) {
          for (int w : graph[u])
            if (!cycle[w]) {
              if (prev[w] != -1 && prev[w] != u) {
                for (int q = w; q != -1; q = prev[q]) {
                  if (!cycle[q]) {
                    cycle[q] = true;
                    ++cnt;
                    pw += b[q];
                  }
                }
                for (int q = u; q != -1; q = prev[q]) {
                  if (!cycle[q]) {
                    cycle[q] = true;
                    ++cnt;
                    pw += b[q];
                  }
                }
                return true;
              }
            }
        }
      return false;
    };
    while (cnt < n && aug())
      ;
    return cnt == n;
  }
  int solve(std::istream& reader) {
    reader >> n >> m;
    a.resize(n);
    for (int i = 1; i < n; ++i) {
      reader >> a[i];
    }
    b.resize(n);
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
    int l = 1, r = *std::max_element(a.begin(), a.end()) + 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (judge(mid))
        r = mid - 1;
      else
        l = mid + 1;
    }
    return r + 1;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;
  int cas;
  reader >> cas;
  while (cas--) {
    printf("%d\n", Solver().solve(reader));
  }
}
