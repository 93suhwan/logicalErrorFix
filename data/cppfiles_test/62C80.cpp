#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string dirs = "DRUL";
bool Free[N][N];
int dir[N][N][4];
int Freecnt = 0;
long long sum01 = 0;
int n, m, q;
bool isFree(int x, int y) {
  return (1 <= x && x <= n && 1 <= y && y <= m && Free[x][y]);
}
int cnt(int x, int y, int dir) {
  if (!isFree(x, y)) return 0;
  return 1 + cnt(x + dx[dir], y + dy[dir], dir ^ 1);
}
void add(int x, int y, int dir, int dz) {
  if (!isFree(x, y)) return;
  ::dir[x][y][dir ^ 2] += dz;
  if (dir >= 2) sum01 += dz;
  return add(x + dx[dir], y + dy[dir], dir ^ 1, dz);
}
void flip(int x, int y) {
  if (Free[x][y] == 0) {
    Free[x][y] = 1;
    Freecnt++;
    for (int dd = 0; dd < 4; dd++) {
      int cc = cnt(x, y, dd);
      add(x, y, dd ^ 3, cc);
    }
  } else {
    for (int dd = 0; dd < 4; dd++) {
      int cc = cnt(x, y, dd);
      add(x, y, dd ^ 3, -cc);
    }
    Free[x][y] = 0;
    Freecnt--;
  }
}
void init() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      Free[i][j] = 1;
      Freecnt++;
      dir[i][j][2] = dir[i][j][3] = 1;
      if (i) dir[i][j][2] += dir[i - 1][j][3];
      if (j) dir[i][j][3] += dir[i][j - 1][2];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      dir[i][j][0] = dir[i][j][1] = 1;
      if (i < n) dir[i][j][0] += dir[i + 1][j][1];
      if (j < m) dir[i][j][1] += dir[i][j + 1][0];
      sum01 += dir[i][j][0] + dir[i][j][1];
    }
  }
}
void all() {
  cout << sum01 << " " << Freecnt << " " << sum01 - Freecnt << endl;
  for (int d = 0; d < 4; d++) {
    cout << d << " -----> " << endl;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << dir[i][j][d] << " ";
      }
      cout << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  init();
  while (q--) {
    int x, y;
    cin >> x >> y;
    flip(x, y);
    cout << sum01 - Freecnt << "\n";
    cout.flush();
  }
}
