#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int t;
int n, k;
vector<int> g[110];
int dep[110], dp[110][110];
inline void upd(int &x, int y) { x = (x + y) % mod; }
void dfs(int x, int fa, int d, int &cnt) {
  if (dep[x] == d) cnt++;
  for (int i = 0; i < (int)g[x].size(); i++) {
    int to = g[x][i];
    if (to == fa) continue;
    dep[to] = dep[x] + 1;
    dfs(to, x, d, cnt);
  }
}
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) g[i].clear();
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (k == 2) {
    cout << 1ll * n * (n - 1) / 2 % mod << endl;
    return;
  }
  int ans = 0;
  for (int r = 0; r < n; r++)
    for (int d = 1; d <= n; d++) {
      if ((int)g[r].size() < k) continue;
      dp[0][0] = 1;
      for (int i = 0; i < (int)g[r].size(); i++) {
        int cnt = 0;
        dep[g[r][i]] = 1;
        dfs(g[r][i], r, d, cnt);
        for (int j = 0; j <= i + 1; j++) dp[i + 1][j] = 0;
        for (int j = 0; j <= i; j++) {
          if (cnt > 0) upd(dp[i + 1][j + 1], 1ll * dp[i][j] * cnt % mod);
          upd(dp[i + 1][j], dp[i][j]);
        }
      }
      cout << endl;
      upd(ans, dp[(int)g[r].size()][k]);
    }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
