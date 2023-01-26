#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1000 + 100;
int tt, n, m, ct;
int a[N][N];
int ok[N][N];
int dir[6][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
void dfs(int x, int y) {
  ok[x][y] = 1;
  ct++;
  for (int i = 0; i < 4; i++) {
    int tx = x + dir[i][0];
    int ty = y + dir[i][1];
    if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
    if (!ok[tx][ty] && !((1 << i) & a[x][y])) {
      dfs(tx, ty);
    }
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  tt = 1;
  while (tt--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        ct = 0;
        if (!ok[i][j]) {
          dfs(i, j);
          v.push_back(ct);
        }
      }
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < (int)v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
