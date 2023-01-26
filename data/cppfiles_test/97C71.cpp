#include <bits/stdc++.h>
using namespace std;
vector<vector<int64_t>> g;
vector<int64_t> vis;
map<pair<int64_t, int64_t>, int64_t> r;
map<int64_t, pair<int64_t, int64_t>> o;
map<int64_t, int64_t> mvp;
vector<int64_t> path;
vector<int64_t> dv;
int64_t dfs(int v, int d) {
  vis[v] = 1;
  dv[v] = d;
  path.push_back(v);
  mvp[v] = path.size() - 1;
  for (int i = 0; i < g[v].size(); ++i) {
    if (!vis[g[v][i]]) {
      if (dfs(g[v][i], 1 - d)) return 1;
    } else {
      if (abs(mvp[g[v][i]] - mvp[v]) % 2 == 0) {
        return 1;
      }
    }
  }
  path.pop_back();
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  char a[n][m];
  int64_t b[n][m];
  int64_t num = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == '.') {
        o[num] = {i, j};
        r[{i, j}] = num++;
      }
    }
  }
  g.resize(num);
  vis.resize(num);
  dv.resize(num);
  int64_t no = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 'X') {
        vector<int64_t> so;
        if (i != 0 && a[i - 1][j] == '.') so.push_back(r[{i - 1, j}]);
        if (i != n - 1 && a[i + 1][j] == '.') so.push_back(r[{i + 1, j}]);
        if (j != 0 && a[i][j - 1] == '.') so.push_back(r[{i, j - 1}]);
        if (j != m - 1 && a[i][j + 1] == '.') so.push_back(r[{i, j + 1}]);
        if (so.size() % 2 == 1) {
          no = 1;
        } else {
          if (so.size() == 2) {
            b[i][j] = 5;
            g[so[0]].push_back(so[1]);
            g[so[1]].push_back(so[0]);
          } else if (so.size() == 4) {
            g[so[0]].push_back(so[2]);
            g[so[2]].push_back(so[0]);
            g[so[1]].push_back(so[3]);
            g[so[3]].push_back(so[1]);
            b[i][j] = 10;
          } else
            b[i][j] = 0;
        }
      }
    }
  }
  if (no) {
    cout << "NO\n";
  } else {
    int no2 = 0;
    for (int i = 0; i < num; ++i) {
      if (!vis[i]) {
        if (dfs(i, 0)) no2 = 1;
      }
    }
    if (no2) {
      cout << "NO\n";
      return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] == 'X')
          cout << b[i][j] << ' ';
        else
          cout << ((dv[r[{i, j}]]) ? 4 : 1) << ' ';
      }
      cout << "\n";
    }
  }
}
