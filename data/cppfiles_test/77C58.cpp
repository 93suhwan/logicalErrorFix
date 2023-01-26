#include <bits/stdc++.h>
using namespace std;
vector<int64_t> vis;
vector<int64_t> c;
set<pair<int64_t, int64_t>> r;
int64_t n, m;
void dfs(int64_t v) {
  c.back()++;
  vis[v] = 1;
  if (r.find({v, v + m}) != r.end() && vis[v + m] == 0) dfs(v + m);
  if (r.find({v, v + 1}) != r.end() && vis[v + 1] == 0) dfs(v + 1);
  if (r.find({v, v - m}) != r.end() && vis[v - m] == 0) dfs(v - m);
  if (r.find({v, v - 1}) != r.end() && vis[v - 1] == 0) dfs(v - 1);
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  vis.resize(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int64_t x;
      cin >> x;
      if (i != n - 1 && (x & 2) == 0) {
        r.insert(make_pair(i * m + j, (i + 1) * m + j));
        r.insert(make_pair((i + 1) * m + j, i * m + j));
      }
      if (j != m - 1 && (x & 4) == 0) {
        r.insert(make_pair(i * m + j, i * m + j + 1));
        r.insert(make_pair(i * m + j + 1, i * m + j));
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!vis[i * m + j]) {
        c.resize(c.size() + 1);
        dfs(i * m + j);
      }
    }
  }
  sort(c.rbegin(), c.rend());
  for (int i = 0; i < c.size(); ++i) cout << c[i] << ' ';
  return 0;
}
