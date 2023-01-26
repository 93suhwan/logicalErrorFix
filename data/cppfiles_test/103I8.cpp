#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long LINF = 1e18;
int n, m;
pair<int, int> adj[N][N];
int vis[N][N], active[N][N], dist[N][N];
vector<pair<int, int>> cur;
bool check(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
void dfs1(int u, int v) {
  int i = u;
  int j = v;
  while (i != -1 && !vis[i][j]) {
    vis[i][j] = 1;
    active[i][j] = 1;
    cur.push_back({i, j});
    auto [ii, jj] = adj[i][j];
    if (check(ii, jj)) {
      if (!vis[ii][jj]) {
        ;
      } else if (active[ii][jj]) {
        int x = ii;
        int y = jj;
        int ct = 0;
        while (x != i || y != j) {
          ct++;
          int tx = x;
          int ty = y;
          x = adj[tx][ty].first;
          y = adj[tx][ty].second;
        }
        ct++;
        x = ii;
        y = jj;
        while (x != i || y != j) {
          dist[x][y] = ct;
          int tx = x;
          int ty = y;
          x = adj[tx][ty].first;
          y = adj[tx][ty].second;
        }
        dist[i][j] = ct;
      } else {
        if (!dist[i][j]) dist[i][j] = dist[ii][jj] + 1;
      }
    }
    i = ii;
    j = jj;
  }
  while (cur.size()) {
    auto [i, j] = cur.back();
    cur.pop_back();
    if (!dist[i][j]) {
      dist[i][j] = dist[adj[i][j].first][adj[i][j].second] + 1;
    }
    active[i][j] = 0;
  }
}
map<char, pair<int, int>> dir;
void solve() {
  cin >> n >> m;
  cur.clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vis[i][j] = 0;
      dist[i][j] = 0;
      active[i][j] = 0;
      char x;
      cin >> x;
      int ii = i + dir[x].first;
      int jj = j + dir[x].second;
      if (check(ii, jj)) {
        adj[i][j] = {ii, jj};
      } else {
        adj[i][j] = {-1, -1};
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        dfs1(i, j);
      }
    }
  }
  pair<int, pair<int, int>> ans = {0, {0, 0}};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans = max({dist[i][j], {i + 1, j + 1}}, ans);
    }
  }
  cout << ans.second.first << ' ' << ans.second.second << ' ' << ans.first
       << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  dir['L'] = {0, -1};
  dir['R'] = {0, 1};
  dir['D'] = {1, 0};
  dir['U'] = {-1, 0};
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
