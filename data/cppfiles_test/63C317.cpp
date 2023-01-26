#include <bits/stdc++.h>
using namespace std;
class dsu {
 public:
  vector<int> p;
  int n;
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};
void dfs(int c, int u, dsu &p, vector<vector<int> > v) {
  if (u != 0) {
    p.unite(u, c);
  }
  for (int i = 0; i < v[c].size(); i++) {
    int next = v[c][i];
    if (next != u) dfs(next, c, p, v);
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  vector<vector<int> > v1(n + 1), v2(n + 1);
  for (int i = 1; i <= m1; i++) {
    int x, y;
    cin >> x >> y;
    v1[x].push_back(y);
    v1[y].push_back(x);
  }
  for (int i = 1; i <= m2; i++) {
    int x, y;
    cin >> x >> y;
    v2[x].push_back(y);
    v2[y].push_back(x);
  }
  dsu p1(n + 1), p2(n + 1);
  for (int i = 1; i <= n; i++) {
    if (p1.get(i) == i) dfs(i, 0, p1, v1);
    if (p2.get(i) == i) dfs(i, 0, p2, v2);
  }
  vector<pair<int, int> > ans;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (p1.get(i) != p1.get(j) && p2.get(i) != p2.get(j)) {
        ans.push_back({i, j});
        p1.unite(i, j);
        p2.unite(i, j);
      }
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  }
}
