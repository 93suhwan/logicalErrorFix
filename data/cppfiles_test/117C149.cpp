#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int countempty(int r, int c, vector<string>& g) {
  int cnt = 0;
  int nr, nc;
  for (int i = 0; i < 4; i++) {
    nr = r + dx[i];
    nc = c + dy[i];
    if (nr >= n || nc >= m || nr < 0 || nc < 0) continue;
    if (g[nr][nc] == '.') cnt++;
  }
  return cnt;
}
void dfs(int r, int c, vector<string>& g) {
  int nr, nc;
  for (int i = 0; i < 4; i++) {
    nr = r + dx[i];
    nc = c + dy[i];
    if (nr >= n || nc >= m || nr < 0 || nc < 0) continue;
    if (g[nr][nc] == '.' && countempty(nr, nc, g) <= 1) {
      g[nr][nc] = '+';
      dfs(nr, nc, g);
    }
  }
  return;
}
void solve() {
  cin >> n >> m;
  vector<string> g(n);
  for (int i = 0; i < n; i++) cin >> g[i];
  int lr, lc;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'L') {
        lr = i;
        lc = j;
        break;
      }
    }
  dfs(lr, lc, g);
  for (int i = 0; i < n; i++) {
    cout << g[i] << '\n';
  }
  return;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}
