#include <bits/stdc++.h>
using namespace std;
const bool MULTITEST = 1;
int n, m, sum = 0;
vector<string> mat;
vector<vector<int>> used, cnt, beg, par;
void dfs(int y, int x) {
  used[y][x] = 1;
  sum++;
  int ny = y, nx = x;
  char c = mat[y][x];
  if (c == 'R') nx++;
  if (c == 'L') nx--;
  if (c == 'U') ny--;
  if (c == 'D') ny++;
  if (!used[ny][nx]) {
    dfs(ny, nx);
  } else {
    sum++;
  }
  cnt[y][x] = cnt[ny][nx] + 1;
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
  for (int i = 0; i < n; i++) {
    if (mat[i][0] == 'L') {
      used[i][0] = 1;
      cnt[i][0] = 1;
    }
    if (mat[i][m - 1] == 'R') {
      used[i][m - 1] = 1;
      cnt[i][m - 1] = 1;
    }
  }
  for (int j = 0; j < m; j++) {
    if (mat[0][j] == 'U') {
      used[0][j] = 1;
      cnt[0][j] = 1;
    }
    if (mat[n - 1][j] == 'D') {
      used[n - 1][j] = 1;
      cnt[n - 1][j] = 1;
    }
  }
  sum = 0;
  if (!used[0][0]) dfs(0, 0);
  if (sum == n * m) {
    cout << 1 << " " << 1 << " " << sum << "\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      used[i][j] = 0;
      cnt[i][j] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (mat[i][0] == 'L') {
      used[i][0] = 1;
      cnt[i][0] = 1;
    }
    if (mat[i][m - 1] == 'R') {
      used[i][m - 1] = 1;
      cnt[i][m - 1] = 1;
    }
  }
  for (int j = 0; j < m; j++) {
    if (mat[0][j] == 'U') {
      used[0][j] = 1;
      cnt[0][j] = 1;
    }
    if (mat[n - 1][j] == 'D') {
      used[n - 1][j] = 1;
      cnt[n - 1][j] = 1;
    }
  }
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
    if (mat[i][0] == 'L') {
      used[i][0] = 1;
      cnt[i][0] = 1;
    }
    if (mat[i][m - 1] == 'R') {
      used[i][m - 1] = 1;
      cnt[i][m - 1] = 1;
    }
  }
  for (int j = 0; j < m; j++) {
    if (mat[0][j] == 'U') {
      used[0][j] = 1;
      cnt[0][j] = 1;
    }
    if (mat[n - 1][j] == 'D') {
      used[n - 1][j] = 1;
      cnt[n - 1][j] = 1;
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
