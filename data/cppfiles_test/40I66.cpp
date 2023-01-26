#include <bits/stdc++.h>
using namespace std;
int par[300030];
vector<vector<int>> graph;
vector<int> prv;
vector<bool> vis;
vector<vector<int>> ng;
vector<pair<int, int>> edge;
vector<int> c;
int find(int x) { return par[x] = (par[x] == x ? x : find(par[x])); }
void merge(int x, int y) { par[find(x)] = find(y); }
void dfs1(int p, int cur, int target) {
  vis[cur] = true;
  prv[cur] = p;
  for (int x : graph[cur]) {
    if (!vis[x]) {
      dfs1(cur, x, target);
    }
  }
}
void dfs2(int x) {
  vis[x] = true;
  for (int y : ng[x]) {
    if (!vis[y]) dfs2(y);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  c.assign(n, 0);
  graph.assign(n, vector<int>());
  ng.assign(n, vector<int>());
  for (int i = 0; i < n; i++) par[i] = i;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    edge.push_back({x, y});
    if (find(x) != find(y)) {
      graph[x].push_back(y);
      graph[y].push_back(x);
      merge(x, y);
    }
  }
  int q;
  cin >> q;
  vector<vector<int>> ans;
  while (q--) {
    prv.assign(n, -1);
    vis.assign(n, false);
    int from, to;
    cin >> from >> to;
    from--;
    to--;
    c[from]++;
    c[to]++;
    dfs1(-1, from, to);
    vector<int> vs;
    while (to != from) {
      vs.push_back(to);
      to = prv[to];
    }
    vs.push_back(to);
    reverse(vs.begin(), vs.end());
    ans.push_back(vs);
  }
  for (int i = 0; i < m; i++) {
    if (c[edge[i].first] % 2 == 1 && c[edge[i].second] % 2 == 1) {
      ng[edge[i].first].push_back(edge[i].second);
      ng[edge[i].second].push_back(edge[i].first);
    }
  }
  int cnt = 0;
  vis.assign(n, false);
  for (int i = 0; i < n; i++) {
    if (!vis[i] && c[i] % 2 != 0) {
      cnt++;
      dfs2(i);
    }
  }
  if (cnt == 0) {
    cout << "YES\n";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].size() << '\n';
      for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] + 1 << ' ';
      }
      cout << '\n';
    }
  } else {
    cout << "NO\n";
    cout << cnt << '\n';
  }
}
