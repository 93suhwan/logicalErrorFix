#include <bits/stdc++.h>
using namespace std;
int t, n, ok, d, mod = 998244353;
int dp[100010], ans[100010];
vector<int> g[100010];
void dfs(int u, int parent) {
  if (!ok) return;
  for (int v : g[u])
    if (v ^ parent) dfs(v, u);
  if (dp[u] % d != 0) {
    if (parent != 0) dp[u]++;
    if (dp[u] % d != 0) {
      ok = 0;
      return;
    }
  } else
    dp[parent]++;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) ans[i] = 0;
    ans[1] = 1;
    for (int i = 1; i < n; i++) ans[1] = (ans[1] + ans[1]) % mod;
    for (d = 2; d <= n; d++)
      if ((n - 1) % d == 0) {
        ok = 1;
        dfs(1, 0);
        ans[d] = ok;
        for (int i = 0; i <= n; i++) dp[i] = 0;
      }
    for (int i = n; i >= 1; i--)
      for (int j = i + i; j <= n; j += i)
        ans[i] = (ans[i] - ans[j] + mod) % mod;
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) g[i].clear();
  }
}
