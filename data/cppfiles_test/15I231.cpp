#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
const int mod = 1e9 + 7;
const int INF = 1e9 + 9;
vector<int> g[maxn];
int dp[maxn][maxn];
int depth[maxn][maxn];
int cc = 0;
inline int dfs(int x, int p, int t, int level) {
  if (t == -1) {
    int tot = 0;
    for (auto i : g[x]) dfs(i, x, ++tot, 1);
    cc = tot;
  } else {
    int x = level;
    depth[t][level]++;
    for (auto i : g[x]) {
      if (i == p) continue;
      x = max(dfs(i, x, t, level + 1), x);
    }
  }
  return x;
}
inline int rundp(int n, int level, int k) {
  dp[0][0] = 1;
  for (int i = 1; i <= cc; i++) {
    for (int c = 0; c <= k; c++) {
      if (c == 0)
        dp[i][c] = dp[i - 1][c];
      else
        dp[i][c] =
            (dp[i - 1][c] + dp[i - 1][c - 1] * depth[i][level] % mod) % mod;
    }
  }
  return dp[cc][k];
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    if (k == 2) {
      cout << n * (n - 1) / 2 << '\n';
      continue;
    }
    for (int i = 1; i <= n; i++) {
      memset(depth, 0, sizeof(depth));
      cc = 0;
      int d = dfs(i, -1, -1, 0);
      for (int j = 1; j <= d; j++) {
        memset(dp, 0, sizeof(dp));
        ans = (rundp(n, j, k) + ans) % mod;
      }
    }
    cout << ans << '\n';
  }
}
