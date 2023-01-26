#include <bits/stdc++.h>
using namespace std;
void optIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
string s[520];
int n, m;
int dirx[] = {0, 0, -1, 1};
int diry[] = {-1, 1, 0, 0};
int id = 0;
int vis[520][520], ans[520][520];
void dfs(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return;
  if (s[x][y] == 'X') return;
  if (vis[x][y]) return;
  vis[x][y] = id;
  for (int i = 0; i < 4; ++i) dfs(x + dirx[i], y + diry[i]);
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> s[i];
  bool ok = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'X') {
        int cnt = 0;
        if (s[i][j + 1] == 'X') cnt++;
        if (s[i][j - 1] == 'X') cnt++;
        if (s[i + 1][j] == 'X') cnt++;
        if (s[i - 1][j] == 'X') cnt++;
        if (cnt % 2 != 0) ok = 0;
        ans[i][j] = 5 * (2 - (cnt / 2));
        continue;
      }
      if (vis[i][j]) continue;
      id++;
      dfs(i, j);
    }
  if (!ok) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  for (int i = 0; i < n; ++i) {
    int lid = vis[i][0];
    int s = (i & 1) ? 1 : 4;
    for (int j = 0; j < m; ++j) {
      if (!vis[i][j]) continue;
      if (lid != vis[i][j]) {
        lid = vis[i][j];
        s = 5 - s;
      }
      ans[i][j] = s;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}
int main() {
  optIO();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
