#include <bits/stdc++.h>
using namespace std;
char ans[101][101];
int n, m, k;
char c = 'a';
int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};
bool isin(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m); }
char nextChar(int x, int y) {
  vector<int> vis(26, 0);
  for (int k = 0; k < 8; k++) {
    int X = x + dx[k];
    int Y = y + dy[k];
    if (isin(X, Y) && ans[X][Y] != '0') vis[ans[X][Y] - 'a'] = 1;
  }
  for (int i = 0; i < 26; i++)
    if (!vis[i]) return (char)(i + 97);
  return 'z';
}
bool ansNotExists = false;
void fillColumn(int j) {
  if (ansNotExists) return;
  int i = 0;
  while (ans[i][j] != '0' && i < n) {
    i++;
  }
  if ((n - i) % 2 != 0) {
    ansNotExists = true;
    return;
  }
  for (; i < n && i + 1 < n; i += 2) {
    char color = nextChar(i, j);
    ans[i][j] = color;
    ans[i + 1][j] = color;
  }
}
void fillColumns() {
  for (int j = 0; j < m; j++) fillColumn(j);
}
void fillRow(int i) {
  if (k == 0) return;
  for (int j = 0; j < m && j + 1 < m; j += 2) {
    char color = nextChar(i, j);
    ans[i][j] = color;
    ans[i][j + 1] = color;
    k--;
  }
}
void fill(int i, int j) {
  char color = nextChar(i, j);
  ans[i][j] = color;
  ans[i][j + 1] = color;
}
void solve() {
  ansNotExists = false;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) ans[i][j] = '0';
  int row = 0;
  if (n % 2) {
    row = 1;
    int toFill = m / 2;
    if (toFill > k) {
      cout << "NO\n";
      return;
    }
    fillRow(0);
  }
  if (k != 0) {
    int toFill = m / 2 + m / 2;
    while (k && row < n) {
      int col = 0;
      while (col < m && col + 1 < m && k) {
        fill(row, col);
        k--;
        if (row + 1 < n && k) {
          fill(row + 1, col);
          k--;
        }
        col += 2;
      }
      row += 2;
    }
  }
  fillColumns();
  if (ansNotExists || k != 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++, cout << "\n")
    for (int j = 0; j < m; j++) cout << ans[i][j] << "";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  for (int testcase = 1; testcase <= T; testcase++) {
    solve();
  }
  return 0;
}
