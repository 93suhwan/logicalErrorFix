#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, a[1050][1050];
bool used[1050][1050];
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
bool has_wall(int x, int y, int dir) { return !!(a[x][y] & (1 << dir)); }
int dfs(int x, int y) {
  used[x][y] = true;
  int area = 1;
  for (int k = 0; k < 4; k++) {
    int xx = x + dx[k], yy = y + dy[k];
    if (!valid(xx, yy) || used[xx][yy] || has_wall(x, y, k)) continue;
    area += dfs(xx, yy);
  }
  return area;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> ans;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (!used[x][y]) {
        ans.push_back(dfs(x, y));
      }
    }
  }
  sort((ans).rbegin(), (ans).rend());
  for (int x : ans) cout << x << " ";
  cout << endl;
}
