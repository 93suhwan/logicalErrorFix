#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 99, sq = 500;
int n, q, sz[N], ans[N], a[N][2], dp[N][sq];
vector<int> g[N];
void dfs1(int x, int par) {
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] != par) {
      dfs1(g[x][i], x);
      for (int j = 0; j < sq; j++) {
        dp[x][j] += max(1, dp[g[x][i]][j] - j);
      }
    }
  }
}
void dfs2(int x, int par) {
  sz[x] = 1;
  dp[x][0] = -N;
  for (int i = 1; i < sq; i++) dp[x][i] = 0;
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] != par) {
      dfs2(g[x][i], x);
      for (int j = sz[x] / sq + 1; j >= 0; j--) {
        for (int k = sz[g[x][i]] / sq + 1; k >= 0; k--) {
          dp[x][j + k] = max(dp[x][j + k], dp[x][j] + dp[g[x][i]][k]);
        }
      }
      sz[x] += sz[g[x][i]];
    }
  }
  dp[x][0] = 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    u = i, v = i + 1;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1, 0);
  return 0;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> a[i][0] >> a[i][1];
    if (a[i][1] < sq) {
      ans[i] = dp[a[i][0]][a[i][1]];
    }
  }
  dfs2(1, 0);
  for (int i = 0; i < q; i++) {
    if (a[i][1] >= sq) {
      int res = 0, u = a[i][0], x = a[i][1];
      for (int j = 1; j < sq; j++) {
        res = max(res, dp[u][j] - (j - 1) * x);
      }
      ans[i] = res;
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
}
