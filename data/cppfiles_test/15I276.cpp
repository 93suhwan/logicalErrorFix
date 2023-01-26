#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int mod = 1e9 + 7;
vector<int> g[maxn];
int dp[maxn][maxn];
int c[maxn][maxn];
int cnt[maxn];
void dfs(int u, int fa, int d) {
  cnt[d]++;
  for (int i = 0; i < g[u].size(); i++) {
    int j = g[u][i];
    if (j == fa) continue;
    dfs(j, u, d + 1);
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long ans = 0;
  if (k == 2) {
    ans = 1ll * n * (n - 1) / 2;
    ans %= mod;
    cout << ans << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    memset(dp, 0, sizeof dp);
    for (int d = 1; d <= n; d++) dp[d][0] = 1;
    for (int j = 0; j < g[i].size(); j++) {
      memset(cnt, 0, sizeof(cnt));
      dfs(j, i, 1);
      for (int d = 1; d <= n; d++) {
        for (int q = k; q >= 1; q--) {
          dp[d][q] = (dp[d][q] + cnt[d] * dp[d][q - 1]) % mod;
        }
      }
      for (int d = 1; d <= n; d++) {
        ans += dp[d][k];
        if (ans >= mod) ans -= mod;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
