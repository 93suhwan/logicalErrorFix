#include <bits/stdc++.h>
using namespace std;
template <typename T>
using matrix = vector<vector<T>>;
const long long INFL = (1LL << 62) - 1;
const int INF = (1 << 30) - 1;
const double EPS = 1e-7;
const int MOD = 1e9 + 7;
const int RANDOM =
    chrono::high_resolution_clock::now().time_since_epoch().count();
const int MAXN = 2005;
int grid[MAXN][MAXN], marc[MAXN][MAXN], dp[MAXN][MAXN];
int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};
void getcycle(int x, int y) {
  int x2 = x + dx[grid[x][y]], y2 = y + dy[grid[x][y]];
  int ct = 1;
  while (x2 != x || y2 != y) {
    ct++;
    int tmp = x2 + dx[grid[x2][y2]];
    y2 = y2 + dy[grid[x2][y2]];
    x2 = tmp;
  }
  dp[x][y] = ct;
  x2 = x + dx[grid[x][y]], y2 = y + dy[grid[x][y]];
  while (x2 != x || y2 != y) {
    dp[x2][y2] = ct;
    int tmp = x2 + dx[grid[x2][y2]];
    y2 = y2 + dy[grid[x2][y2]];
    x2 = tmp;
  }
}
void dfs(int x, int y) {
  marc[x][y] = 1;
  int jx = x + dx[grid[x][y]], jy = y + dy[grid[x][y]];
  if (dp[jx][jy] == -1) {
    if (marc[jx][jy])
      getcycle(jx, jy);
    else
      dfs(jx, jy);
  }
  if (dp[x][y] == -1) dp[x][y] = dp[jx][jy] + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> trans(255);
  trans['U'] = 2;
  trans['D'] = 0;
  trans['R'] = 1;
  trans['L'] = 3;
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= m + 1; j++) {
        marc[i][j] = 1;
        dp[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char a;
        cin >> a;
        grid[i][j] = trans[a];
        marc[i][j] = 0;
        dp[i][j] = -1;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (dp[i][j] == -1) {
          dfs(i, j);
        }
      }
    }
    int maxi = -1;
    pair<int, int> resp = {0, 0};
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (dp[i][j] > maxi) {
          maxi = dp[i][j];
          resp = {i, j};
        }
      }
    }
    cout << resp.first << ' ' << resp.second << ' ' << maxi << '\n';
  }
  return 0;
}
