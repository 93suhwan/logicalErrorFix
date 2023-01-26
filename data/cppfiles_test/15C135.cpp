#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int dp[N][N];
int cnt[N];
int dep[N];
vector<int> v[N];
const int mod = 1e9 + 7;
void dfs(int u, int fa, int d) {
  cnt[d]++;
  for (auto j : v[u]) {
    if (j == fa) continue;
    dfs(j, u, d + 1);
  }
}
void solve() {
  memset(dp, 0, sizeof dp);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) v[i].clear();
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  if (m == 2) {
    cout << n * (n - 1) / 2 << endl;
    return;
  }
  int ans = 0;
  for (int root = 1; root <= n; root++) {
    int ct = 0;
    for (int dd = 1; dd <= n; dd++) {
      dp[root][0] = 1;
      for (auto j : v[root]) {
        for (int kk = 1; kk <= n; kk++) cnt[kk] = 0;
        dfs(j, root, 1);
        if (cnt[dd])
          for (int k = m; k >= 1; k--)
            dp[root][k] =
                (1ll * cnt[dd] * dp[root][k - 1] % mod + dp[root][k]) % mod;
      }
      ans = (ans + dp[root][m]) % mod;
      for (int j = 1; j <= m; j++) dp[root][j] = 0;
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
