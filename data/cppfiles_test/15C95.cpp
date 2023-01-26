#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxN = 1e3 + 5, mod = 1e9 + 7, LOG = 20;
int n, k, cnt[mxN], ans;
int dp[mxN][mxN];
vector<int> adj[mxN];
void calc(int v, int p, int dep = 1) {
  ++cnt[dep];
  for (auto to : adj[v]) {
    if (to != p) calc(to, v, dep + 1);
  }
}
void get(int node) {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) dp[i][j] = 0;
  }
  for (int i = 1; i <= n; ++i) dp[0][i] = 1;
  int now = 0;
  for (auto to : adj[node]) {
    calc(to, node);
    ++now;
    for (int d = 1; d <= n; ++d) {
      for (int j = now; j > 0; j--)
        dp[j][d] = (dp[j][d] + dp[j - 1][d] * 1ll * cnt[d] % mod) % mod;
    }
    for (int i = 1; i <= n; ++i) cnt[i] = 0;
  }
  for (int i = 1; i <= n; ++i) ans = (ans + dp[k][i]) % mod;
}
void solve() {
  cin >> n >> k;
  ans = 0;
  for (int i = 1; i <= n; ++i) adj[i].clear();
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (k == 2) {
    cout << (n * 1ll * (n - 1) / 2) % mod;
    return;
  }
  for (int c = 1; c <= n; ++c) {
    get(c);
  }
  cout << ans;
}
int main() {
  ios ::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
