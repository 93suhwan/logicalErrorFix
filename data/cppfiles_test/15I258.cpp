#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<bool>> vs(n, vector<bool>(m));
  vector<string> s(n);
  int dx[] = {-1, -1}, dy[] = {-1, 1};
  for (auto &i : s) cin >> i;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*') {
        int x = i + dx[0], y = j + dy[0], l = 0, r = 0;
        while (0 <= x && x < n && 0 <= y && y < m && s[x][y] == '*') {
          l++, x += dx[0], y += dy[0];
        }
        x = i + dx[1], y = j + dy[1];
        while (0 <= x && x < n && 0 <= y && y < m && s[x][y] == '*') {
          r++, x += dx[1], y += dy[1];
        }
        if (k <= min(l, r)) {
          vs[i][j] = true;
          x = i + dx[0], y = j + dx[0];
          while (0 <= x && x < n && 0 <= y && y < m && s[x][y] == '*') {
            vs[x][y] = true, x += dx[0], y += dy[0];
          }
          x = i + dx[1], y = j + dy[1];
          while (0 <= x && x < n && 0 <= y && y < m && s[x][y] == '*') {
            vs[x][y] = true, x += dx[1], y += dy[1];
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*' && vs[i][j] == false) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
