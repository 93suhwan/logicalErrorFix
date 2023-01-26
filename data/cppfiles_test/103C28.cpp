#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[2008];
char col[2008][2008];
int d[2008][2008];
int cycle(int x, int y) {
  if (col[x][y] == 'c') return 0;
  col[x][y] = 'c';
  if (s[x][y] == 'U') return 1 + cycle(x - 1, y);
  if (s[x][y] == 'D') return 1 + cycle(x + 1, y);
  if (s[x][y] == 'L') return 1 + cycle(x, y - 1);
  if (s[x][y] == 'R') return 1 + cycle(x, y + 1);
}
int dfs(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return 0;
  if (col[x][y] == 'b') return d[x][y];
  if (col[x][y] == 'g') {
    return cycle(x, y);
  }
  int ct = 0;
  col[x][y] = 'g';
  if (s[x][y] == 'U') ct = dfs(x - 1, y);
  if (s[x][y] == 'D') ct = dfs(x + 1, y);
  if (s[x][y] == 'L') ct = dfs(x, y - 1);
  if (s[x][y] == 'R') ct = dfs(x, y + 1);
  d[x][y] = ct;
  if (col[x][y] == 'g') d[x][y]++;
  col[x][y] = 'b';
  return d[x][y];
}
void solve(int t) {
  int i, j, k, q;
  cin >> n >> m;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= m; j++) {
      col[i][j] = '-';
    }
  }
  for (i = 0; i < n; i++) cin >> s[i];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      dfs(i, j);
    }
  }
  int xx = 0, yy = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (d[xx][yy] < d[i][j]) {
        xx = i;
        yy = j;
      }
    }
  }
  cout << xx + 1 << " " << yy + 1 << " " << d[xx][yy] << endl;
  return;
}
int main() {
  int t, tt = 1;
  cin >> tt;
  for (t = 1; t <= tt; t++) solve(t);
  return 0;
}
