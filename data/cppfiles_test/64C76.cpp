#include <bits/stdc++.h>
using namespace std;
struct Dsu {
  int n;
  vector<int> fa;
  vector<int> siz;
  Dsu(int t) {
    n = t;
    fa.resize(n + 10, 0);
    iota(fa.begin(), fa.end(), 0);
    siz.resize(n + 10, 1);
  }
  void init(int t) {
    n = t;
    fa.resize(0);
    fa.resize(n + 10, 0);
    iota(fa.begin(), fa.end(), 0);
    siz.resize(0);
    siz.resize(n + 10, 1);
  }
  int find(int u) {
    if (fa[u] == u) return u;
    return fa[u] = find(fa[u]);
  }
  void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
      if (siz[fx] <= siz[fy])
        fa[fx] = fy, siz[fy] += siz[fx];
      else
        fa[fy] = fx, siz[fx] += siz[fy];
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  Dsu d1(n), d2(n);
  for (int i = 1; i <= m1; i++) {
    int u, v;
    cin >> u >> v;
    d1.merge(u, v);
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    cin >> u >> v;
    d2.merge(u, v);
  }
  vector<pair<int, int>> ans;
  for (int i = 2; i <= n; i++)
    if (d1.find(i) != d1.find(1) && d2.find(i) != d2.find(1)) {
      d1.merge(1, i);
      d2.merge(1, i);
      ans.push_back({1, i});
    }
  stack<int> s1, s2;
  for (int i = 2; i <= n; i++)
    if (d1.find(i) != d1.find(1) && d2.find(i) == d2.find(1))
      s1.push(i);
    else if (d1.find(i) == d1.find(1) && d2.find(i) != d2.find(1))
      s2.push(i);
  while (!s1.empty() && !s2.empty()) {
    int u = s1.top();
    int v = s2.top();
    if (d1.find(u) == d1.find(1)) {
      s1.pop();
      continue;
    }
    if (d2.find(v) == d2.find(1)) {
      s2.pop();
      continue;
    }
    s1.pop();
    s2.pop();
    ans.push_back({u, v});
    d1.merge(u, v);
    d2.merge(u, v);
  }
  cout << ans.size() << '\n';
  for (auto u : ans) cout << u.first << ' ' << u.second << '\n';
  return 0;
}
