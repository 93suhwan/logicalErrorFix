#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
char s[maxn][maxn];
int dp[maxn][maxn];
int vis[maxn][maxn];
int n, m, sum;
bool flag;
void dfs(int x, int y) {
  vis[x][y] = ++sum;
  int tx = x, ty = y;
  if (s[x][y] == 'U')
    tx--;
  else if (s[x][y] == 'D')
    tx++;
  else if (s[x][y] == 'L')
    ty--;
  else
    ty++;
  if (tx < 1 || tx > n || ty < 1 || ty > m) {
    dp[x][y] = 1;
    vis[x][y] = 0;
    return;
  }
  if (vis[tx][ty]) {
    flag = true;
    sum -= (vis[tx][ty] - 1);
    vis[tx][ty] = 0;
    vis[x][y] = 0;
    dp[x][y] = sum;
    return;
  }
  if (dp[tx][ty] == -1) dfs(tx, ty);
  if (flag)
    dp[x][y] = sum;
  else
    dp[x][y] = dp[tx][ty] + 1;
  if (vis[x][y] == 0) flag = false;
  vis[x][y] = 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) dp[i][j] = -1, vis[i][j] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (dp[i][j] == -1) {
          flag = false;
          sum = 0;
          dfs(i, j);
        }
      }
    }
    int ansy = 1, ansx = 1, ans = dp[1][1];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (dp[i][j] > ans) {
          ans = dp[i][j];
          ansx = i;
          ansy = j;
        }
      }
    }
    printf("%d %d %d\n", ansx, ansy, ans);
  }
}
