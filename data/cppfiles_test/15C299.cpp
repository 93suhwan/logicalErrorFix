#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, k;
char maze[12][22];
bool vis[22][22];
void check(int x, int y) {
  int t = 1;
  while (x - t >= 1 && y - t >= 1) {
    if (maze[x - t][y - t] == '*')
      t++;
    else
      break;
  }
  int temp = t;
  t = 1;
  while (x - t >= 1 && y + t <= m) {
    if (maze[x - t][y + t] == '*')
      t++;
    else
      break;
  }
  temp = min(temp, t);
  temp--;
  if (temp < k) return;
  for (int i = 1; i <= temp; i++) vis[x - i][y - i] = true;
  for (int i = 1; i <= temp; i++) vis[x - i][y + i] = true;
  vis[x][y] = true;
}
void solve() {
  memset(vis, 0, sizeof vis);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> maze[i][j];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (maze[i][j] == '*' && !vis[i][j]) {
        check(i, j);
      }
    }
  }
  bool flag = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (maze[i][j] == '*' && !vis[i][j]) {
        flag = false;
      }
  }
  if (!flag)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
