#include <bits/stdc++.h>
using namespace std;
const bool MULTITEST = 1;
int n, m;
vector<vector<char>> mat;
vector<vector<int>> used, cnt, beg, par;
void dfs(int y, int x, int py, int px) {
  used[y][x] = 1;
  int ny = y, nx = x;
  char c = mat[y][x];
  if (c == 'R') nx++;
  if (c == 'L') nx--;
  if (c == 'U') ny--;
  if (c == 'D') ny++;
  if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
    cnt[y][x] = 1;
  } else {
    if (!used[ny][nx]) {
      dfs(ny, nx, y, x);
    }
    cnt[y][x] = cnt[ny][nx] + 1;
  }
}
void dfs2(int y, int x, int b) {
  used[y][x] = 1;
  beg[y][x] = b;
  int ny = y, nx = x;
  char c = mat[y][x];
  if (c == 'R') nx++;
  if (c == 'L') nx--;
  if (c == 'U') ny--;
  if (c == 'D') ny++;
  if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
    return;
  }
  if (used[ny][nx] == 0) {
    par[ny][nx] = y * m + x;
    dfs2(ny, nx, b);
  } else {
    if (beg[ny][nx] == b) {
      vector<pair<int, int>> path;
      int cy = y, cx = x;
      while (cy != ny || cx != nx) {
        path.push_back({cy, cx});
        int p = par[cy][cx];
        cy = p / m;
        cx = p % m;
      }
      for (int j = 0; j < path.size(); j++) {
        used[path[j].first][path[j].second] = 2;
        cnt[path[j].first][path[j].second] = (int)path.size();
      }
    }
  }
}
int solve() {
  cin >> n >> m;
  mat.clear();
  used.clear();
  cnt.clear();
  beg.clear();
  par.clear();
  mat.resize(n, vector<char>(m));
  used.resize(n, vector<int>(m));
  par.resize(n, vector<int>(m));
  beg.resize(n, vector<int>(m));
  cnt.resize(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!used[i][j]) {
        int b = i * m + j;
        par[i][j] = b;
        dfs2(i, j, b);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (used[i][j] == 1) used[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!used[i][j]) {
        dfs(i, j, i, j);
      }
    }
  }
  int ma = -1, ay = 1, ax = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ma < cnt[i][j]) {
        ma = cnt[i][j];
        ay = i + 1;
        ax = j + 1;
      }
    }
  }
  cout << ay << " " << ax << " " << ma << "\n";
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  if (MULTITEST) cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
