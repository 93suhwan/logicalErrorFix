#include <bits/stdc++.h>
using namespace std;
char arr[2005][2005];
int dp[2005][2005], vis[2005][2005], n, m;
pair<int, int> par[2005][2005];
int dfs1(int i, int j) {
  vis[i][j] = 1;
  int x = i, y = j;
  if (arr[i][j] == 'L') y--;
  if (arr[i][j] == 'R') y++;
  if (arr[i][j] == 'U') x--;
  if (arr[i][j] == 'D') x++;
  if (x < 0 || x >= n || y < 0 || y >= m) {
    vis[i][j] = 2;
    return 0;
  }
  if (vis[x][y] == 0) {
    par[x][y] = {i, j};
    dfs1(x, y);
  } else if (vis[x][y] == 1) {
    int cnt = 1;
    int tx = i, ty = j;
    while (tx != x || ty != y) {
      ++cnt;
      int ttx = par[tx][ty].first;
      int tty = par[tx][ty].second;
      tx = ttx;
      ty = tty;
    }
    tx = i, ty = j;
    while (tx != x || ty != y) {
      dp[tx][ty] = cnt;
      int ttx = par[tx][ty].first;
      int tty = par[tx][ty].second;
      tx = ttx;
      ty = tty;
    }
    dp[tx][ty] = cnt;
  }
  vis[i][j] = 2;
  return 0;
}
int dfs(int i, int j) {
  vis[i][j] = 1;
  int x = i, y = j;
  if (arr[i][j] == 'L') y--;
  if (arr[i][j] == 'R') y++;
  if (arr[i][j] == 'U') x--;
  if (arr[i][j] == 'D') x++;
  if (x < 0 || x >= n || y < 0 || y >= m) {
    dp[i][j] = 1;
    return 1;
  }
  if (vis[x][y] == 0) {
    par[x][y] = {i, j};
    dp[i][j] = max(dp[i][j], 1 + dfs(x, y));
  } else if (vis[x][y] == 1) {
  } else {
    dp[i][j] = 1 + dp[x][y];
  }
  vis[i][j] = 2;
  return dp[i][j];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> arr[i][j];
        dp[i][j] = -1;
        vis[i][j] = 0;
        par[i][j] = {-1, -1};
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (vis[i][j] == 0) {
          par[i][j] = {i, j};
          dfs1(i, j);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (dp[i][j] == -1) vis[i][j] = 0;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (vis[i][j] == 0) {
          par[i][j] = {i, j};
          dfs(i, j);
        }
      }
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (dp[i][j] > dp[x][y]) x = i, y = j;
      }
    }
    cout << x + 1 << " " << y + 1 << " " << dp[x][y] << '\n';
  }
  return 0;
}
