#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> d(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    ++d[u], ++d[v];
  }
  set<pair<int, int>> s;
  for (int i = 0; i < n; ++i) s.emplace(d[i], i);
  vector<int> cur;
  for (int it = 0; it < 5 and !s.empty(); ++it) {
    auto [deg, v] = *s.begin();
    cur.push_back(v);
    s.erase(s.begin());
    for (int u : g[v]) {
      if (s.count(make_pair(d[u], u))) {
        for (int j : g[u]) {
          if (s.count(make_pair(d[j], j))) {
            s.erase(make_pair(d[j], j));
            --d[j];
            s.insert(make_pair(d[j], j));
          }
        }
        s.erase(make_pair(d[u], u));
      }
    }
  }
  if (cur.size() == 5) {
    for (int x : cur) cout << x + 1 << ' ';
    return 0;
  }
  assert(n <= 1000);
  vector<vector<int>> matr(n, vector<int>(n, 1));
  for (int i = 0; i < n; ++i) {
    matr[i][i] = 0;
    for (int j : g[i]) {
      matr[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    d[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matr[i][j]) {
        g[i].push_back(j);
        ++d[i];
      }
    }
  }
  s.clear(), cur.clear();
  for (int i = 0; i < n; ++i) s.emplace(d[i], i);
  for (int it = 0; it < 5 and !s.empty(); ++it) {
    auto [deg, v] = *s.begin();
    cur.push_back(v);
    s.erase(s.begin());
    for (int u : g[v]) {
      if (s.count(make_pair(d[u], u))) {
        for (int j : g[u]) {
          if (s.count(make_pair(d[j], j))) {
            s.erase(make_pair(d[j], j));
            --d[j];
            s.insert(make_pair(d[j], j));
          }
        }
        s.erase(make_pair(d[u], u));
      }
    }
  }
  if (cur.size() == 5) {
    for (int x : cur) cout << x + 1 << ' ';
    return 0;
  }
  cout << -1;
  return 0;
}
