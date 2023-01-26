#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
char maze[maxn][maxn];
int cal(char c) {
  if (c == '.') return 27;
  return c - 'a';
}
char get(bool hang, int x, int y) {
  vector<bool> vis(28, 0);
  if (hang) {
    for (int i = y - 1; i <= y + 2; i++) {
      vis[cal(maze[x - 1][i])] = vis[cal(maze[x + 1][i])] = true;
    }
    vis[cal(maze[x][y - 1])] = vis[cal(maze[x][y + 2])] = true;
  } else {
    for (int i = x - 1; i <= x + 2; i++) {
      vis[cal(maze[i][y - 1])] = vis[cal(maze[i][y + 1])] = true;
    }
    vis[cal(maze[x + 2][y])] = vis[cal(maze[x - 1][y])] = true;
  }
  int cnt = 0;
  while (vis[cnt]) cnt++;
  return cnt + 'a';
}
int check(int n, int m, int k) {
  if (m & 1) m--;
  if (n & 1) {
    k -= m / 2;
    n--;
  }
  int mx = (n / 2) * (m / 2) * 2;
  if (k >= 0 && k % 2 == 0 && k <= mx)
    return k;
  else
    return -1;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int r = check(n, m, k);
  if (r != -1) {
    cout << "YES\n";
    for (int i = 0; i <= n + 1; i++)
      for (int j = 0; j <= m + 1; j++) maze[i][j] = '.';
    int i = 1;
    while (r) {
      for (int j = 1; j <= m && j + 1 <= m && r; j += 2) {
        char now = get(1, i, j);
        maze[i][j] = maze[i][j + 1] = now;
        now = get(1, i + 1, j);
        maze[i + 1][j] = maze[i + 1][j + 1] = now;
        r -= 2;
      }
      i += 2;
    }
    if (n % 2 == 1) {
      for (int j = 1; j <= m; j += 2) {
        char now = get(1, n, j);
        maze[n][j] = maze[n][j + 1] = now;
      }
    }
    for (i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (maze[i][j] == '.') {
          char now = get(0, i, j);
          maze[i][j] = maze[i + 1][j] = now;
        }
      }
    }
    for (int i = 1; i <= n; i++, cout << '\n')
      for (int j = 1; j <= m; j++) cout << maze[i][j];
  } else
    cout << "NO\n";
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
