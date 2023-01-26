#include <bits/stdc++.h>
using namespace std;
char grid[20][20];
int G[20][20];
int diagonalLen(int row, int col, int n, int m, int dr, int dc) {
  int r = row, c = col;
  int len = 0;
  while (r >= 0 && c >= 0 && r < n && c < m) {
    if (grid[r][c] == '*') {
      len++;
      r += dr;
      c += dc;
    } else {
      break;
    }
  }
  return len - 1;
}
int getTickArmLen(int r, int c, int n, int m) {
  int left_d = diagonalLen(r, c, n, m, -1, -1);
  int right_d = diagonalLen(r, c, n, m, -1, +1);
  int d = min(left_d, right_d);
  return d;
}
void makeTickMarked(int row, int col, int n, int m, int d) {
  int r = row, c = col;
  for (int i = 0; i <= d; i++) {
    if (d > G[r][c]) G[r][c] = d;
    r--;
    c--;
  }
  r = row;
  c = col;
  for (int i = 0; i <= d; i++) {
    if (d > G[r][c]) G[r][c] = d;
    r--;
    c++;
  }
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '.')
        G[i][j] = 9;
      else
        G[i][j] = 0;
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '*') {
        int c = j, r = i;
        int d = getTickArmLen(r, c, n, m);
        makeTickMarked(r, c, n, m, d);
      }
    }
  }
  bool possible = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '*' && (G[i][j] < k || G[i][j] == 0)) {
        possible = false;
      }
    }
  }
  if (possible)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return;
}
int main() {
  int tc;
  cin >> tc;
  int t = 0;
  while (t < tc) {
    solve();
    t++;
  }
  return 0;
}
