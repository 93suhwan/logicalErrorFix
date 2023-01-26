#include <bits/stdc++.h>
using namespace std;
const bool MULTITEST = 1;
int n, m;
vector<string> mat;
vector<vector<int>> used, cnt, beg, par;
void dfs(int y, int x) {
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
      dfs(ny, nx);
    }
    cnt[y][x] = cnt[ny][nx] + 1;
  }
}
int solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      used[i][j] = 0;
      par[i][j] = 0;
      beg[i][j] = -1;
      cnt[i][j] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  set<pair<int, int>> was;
  int y1 = 0, x1 = 0;
  while (true) {
    was.insert({y1, x1});
    int ny = y1, nx = x1;
    char c = mat[y1][x1];
    if (c == 'R') nx++;
    if (c == 'L') nx--;
    if (c == 'U') ny--;
    if (c == 'D') ny++;
    if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
      break;
    }
    if (was.find({ny, nx}) != was.end()) break;
    y1 = ny, x1 = nx;
  }
  if (was.size() == n * m) {
    cout << 1 << " " << 1 << " " << n * m << '\n';
    return 0;
  }
  was.clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!used[i][j]) {
        int b = i * m + j;
        par[i][j] = b;
        int y = i, x = j;
        while (true) {
          used[y][x] = 1;
          beg[y][x] = b;
          int ny = y, nx = x;
          char c = mat[y][x];
          if (c == 'R') nx++;
          if (c == 'L') nx--;
          if (c == 'U') ny--;
          if (c == 'D') ny++;
          if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
            break;
          }
          if (used[ny][nx] == 0) {
            par[ny][nx] = y * m + x;
            y = ny;
            x = nx;
          } else {
            if (beg[ny][nx] == b) {
              int k = 0;
              int cy = y, cx = x;
              while (cy != ny || cx != nx) {
                k++;
                int p = par[cy][cx];
                cy = p / m;
                cx = p % m;
              }
              k++;
              cy = y, cx = x;
              while (cy != ny || cx != nx) {
                used[cy][cx] = 2;
                cnt[cy][cx] = k;
                int p = par[cy][cx];
                cy = p / m;
                cx = p % m;
              }
              used[cy][cx] = 2;
              cnt[cy][cx] = k;
            }
            break;
          }
        }
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
        dfs(i, j);
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
  mat.resize(2000);
  used.resize(2000, vector<int>(2000));
  par.resize(2000, vector<int>(2000));
  beg.resize(2000, vector<int>(2000, -1));
  cnt.resize(2000, vector<int>(2000, -1));
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
