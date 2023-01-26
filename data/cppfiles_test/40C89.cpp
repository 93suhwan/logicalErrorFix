#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, q;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cin >> q;
  vector<bool> f(n, false);
  vector<vector<int>> edge(q);
  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edge[i] = {u, v};
    f[u] = !f[u];
    f[v] = !f[v];
  }
  int t = 0;
  for (int i = 0; i < n; ++i) t += f[i];
  if (t == 0) {
    printf("YES\n");
    vector<int> p(n, -1), dep(n, -1);
    list<pair<int, int>> q = {{0, -1}};
    int d = 0;
    while (!q.empty()) {
      list<pair<int, int>> q2;
      for (auto &node : q) {
        int id = node.first, par = node.second;
        dep[id] = d;
        for (auto neigh : g[id]) {
          if (neigh == par || p[neigh] != -1) continue;
          p[neigh] = id;
          q2.push_back({neigh, id});
        }
      }
      swap(q, q2);
      d++;
    }
    for (int i = 0; i < edge.size(); ++i) {
      int x = edge[i][0], y = edge[i][1];
      vector<int> sx, sy;
      while (x != y) {
        if (y == -1 || (x != -1 && dep[x] > dep[y])) {
          sx.push_back(x);
          x = p[x];
        } else {
          sy.push_back(y);
          y = p[y];
        }
      }
      printf("%d\n", sx.size() + sy.size() + 1);
      for (int j = 0; j < sx.size(); ++j) printf("%d ", sx[j] + 1);
      printf("%d ", x + 1);
      for (int j = sy.size() - 1; j >= 0; --j) printf("%d ", sy[j] + 1);
      printf("\n");
    }
  } else {
    printf("NO\n%d\n", t / 2);
  }
  return 0;
}
