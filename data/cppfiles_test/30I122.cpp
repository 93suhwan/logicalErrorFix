#include <bits/stdc++.h>
using namespace std;
struct DSU {
  int n;
  vector<int> pre;
  vector<int> siz;
  DSU(int t) {
    n = t;
    pre.resize(0);
    pre.resize(n + 1, 0);
    siz.resize(0);
    siz.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) pre[i] = i, siz[i] = 1;
  }
  void init(int t) {
    n = t;
    pre.resize(0);
    pre.resize(n + 1, 0);
    siz.resize(0);
    siz.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) pre[i] = i, siz[i] = 1;
  }
  int find(int u) {
    if (pre[u] == u) return u;
    return pre[u] = find(pre[u]);
  }
  void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
      if (siz[fx] <= siz[fy])
        pre[fx] = fy, siz[fy] += siz[fx];
      else
        pre[fy] = fx, siz[fx] += siz[fy];
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  DSU dsu(n);
  vector<bool> prime(1000000 + 10, true);
  vector<vector<int>> p(1000000 + 10);
  vector<vector<int>> pos(1000000 + 10);
  DSU dsu2(1000000 + 1);
  auto init = [&]() {
    for (int i = 2; i <= 1000000 + 1; i++) {
      if (prime[i]) {
        p[i].push_back(i);
        for (int j = i + i; j <= 1000000 + 1; j += i) {
          prime[j] = false;
          p[j].push_back(i);
        }
      }
    }
    for (int i = 1; i <= n; i++)
      for (auto u : p[a[i]]) {
        pos[u].push_back(i);
        dsu2.merge(u, p[a[i]][0]);
      }
    for (int i = 2; i <= 1000000 + 1; i++)
      for (auto u : pos[i]) dsu.merge(u, pos[i][0]);
  };
  init();
  auto ok = [&](int u, int v) {
    if (a[v] == 1) return false;
    for (auto u : p[a[u] + 1])
      if (dsu2.find(u) == dsu2.find(p[a[v]][0])) return true;
    return false;
  };
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (dsu.find(u) == dsu.find(v))
      cout << "0\n";
    else if (ok(u, v) || ok(v, u))
      cout << "1\n";
    else
      cout << "2\n";
  }
  return 0;
}
