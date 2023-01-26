#include <bits/stdc++.h>
const int N = (int)1e5 + 1;
struct dsu {
  int parent[N], size[N];
  int count;
  dsu(const int& n) {
    for (int i = 1; i <= n; i++) parent[i] = i, size[i] = 1;
    count = n;
  }
  int root(int i) {
    while (parent[i] != i) parent[i] = parent[parent[i]], i = parent[i];
    return i;
  }
  void comb(int u, int v) {
    if (size[u] >= size[v])
      parent[v] = parent[u], size[u] += size[v];
    else
      parent[u] = parent[v], size[v] += size[u];
  }
  void add(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return;
    comb(u, v);
    this->count--;
  }
};
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int n, m1, m2, u, v, h, x, y;
  std::cin >> n >> m1 >> m2;
  dsu a(n), b(n);
  for (int i = 0; i < m1; i++) {
    std::cin >> u >> v;
    a.add(u, v);
  }
  for (int i = 0; i < m2; i++) {
    std::cin >> u >> v;
    b.add(u, v);
  }
  h = std::min(a.count - 1, b.count - 1);
  std::cout << h << '\n';
  for (int i = 1; i <= n; i++) {
    if (a.count == 1 || b.count == 1) break;
    for (int j = i + 1; j <= n; j++) {
      if (a.count == 1 || b.count == 1) break;
      u = a.root(i), v = a.root(j);
      x = b.root(i), y = b.root(j);
      if (u != v && x != y) {
        a.comb(u, v);
        b.comb(x, y);
        std::cout << i << ' ' << j << '\n';
      }
    }
  }
}
