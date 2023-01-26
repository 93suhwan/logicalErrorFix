#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
char grid[100][100];
int n, m, k, vi[100][100], len[100][100];
bool in(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
int remove_tick(int x1, int y1, int x2, int y2, int d) {
  d--;
  if (!in(x1, y1) || !in(x2, y2)) {
    return d;
  }
  if (grid[x1][y1] != '*' || grid[x2][y2] != '*') return d;
  d++;
  vi[x1][y1] = 1;
  vi[x2][y2] = 1;
  int nx1 = x1 - 1, ny1 = y1 - 1;
  int nx2 = x2 - 1, ny2 = y2 + 1;
  return remove_tick(nx1, ny1, nx2, ny2, d + 1);
}
void set_d(int x1, int y1, int x2, int y2, int d) {
  if (!in(x1, y1) || !in(x2, y2)) {
    return;
  }
  if (grid[x1][y1] != '*' || grid[x2][y2] != '*') return;
  len[x1][y1] = max(len[x1][y1], d);
  len[x2][y2] = max(len[x2][y2], d);
  int nx1 = x1 - 1, ny1 = y1 - 1;
  int nx2 = x2 - 1, ny2 = y2 + 1;
  return set_d(nx1, ny1, nx2, ny2, d);
}
void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  memset(vi, 0, sizeof vi);
  memset(len, -1, sizeof len);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (grid[i][j] == '*') {
        int sd = remove_tick(i, j, i, j, 0);
        set_d(i, j, i, j, sd);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '*' && len[i][j] < k) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
