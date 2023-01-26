#include <bits/stdc++.h>
using namespace std;
string maps[2005];
int vis[2005][2005];
int cnt[2005][2005];
int n, m;
pair<int, int> dfs(int x, int y, int step) {
  if (x < 0 || y < 0 || x >= n || y >= m) return make_pair(0, 0);
  if (vis[x][y]) {
    cnt[x][y] = step - vis[x][y];
    return make_pair(vis[x][y], cnt[x][y]);
  }
  if (cnt[x][y]) {
    return make_pair(0, cnt[x][y]);
  }
  vis[x][y] = step;
  int nx = x;
  int ny = y;
  if (maps[x][y] == 'L') ny--;
  if (maps[x][y] == 'R') ny++;
  if (maps[x][y] == 'U') nx--;
  if (maps[x][y] == 'D') nx++;
  pair<int, int> res = dfs(nx, ny, step + 1);
  if (!res.first) {
    cnt[x][y] = res.second + 1;
    res.second = cnt[x][y];
  } else {
    cnt[x][y] = res.second;
    if (vis[x][y] == res.first) res.first = 0;
  }
  vis[x][y] = 0;
  return res;
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> maps[i];
    for (int j = 0; j < m; ++j) {
      vis[i][j] = 0;
      cnt[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!cnt[i][j]) {
        dfs(i, j, 1);
      }
    }
  }
  int ans = 0;
  int x, y;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (ans < cnt[i][j]) {
        ans = cnt[i][j];
        x = i + 1;
        y = j + 1;
      }
    }
  }
  printf("%d %d %d\n", x, y, ans);
}
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
