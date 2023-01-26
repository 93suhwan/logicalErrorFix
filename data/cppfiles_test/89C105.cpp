#include <bits/stdc++.h>
using namespace std;
vector<long long int> par, level, deg, adj[(long long int)2e5 + 1],
    str[(long long int)2e5 + 1];
void dfs(long long int u, long long int p = 0) {
  level[u] = level[p] + 1;
  str[level[u]].push_back(u);
  par[u] = p;
  for (long long int x : adj[u])
    if (x != p) {
      deg[u]++;
      dfs(x, u);
    }
}
void solve() {
  long long int n;
  cin >> n;
  for (long long int i = 1; i <= n; i++) adj[i].clear(), str[i].clear();
  level.assign(n + 1, 0);
  par.assign(n + 1, 0);
  deg.assign(n + 1, 0);
  for (long long int i = 0; i < n - 1; i++) {
    long long int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  long long int ans = 0;
  vector<long long int> remov(n + 1, 0);
  for (long long int i = 1; i <= n; i++)
    if (!deg[i]) ans++;
  for (long long int i = n; i >= 2; i--) {
    for (long long int x : str[i]) {
      if (deg[x] == 0) continue;
      bool rem = true;
      for (long long int ch : adj[x]) {
        if (remov[ch] == 1 || level[ch] < level[x]) continue;
        if (deg[ch] != 0) {
          rem = false;
          break;
        }
      }
      if (rem) {
        deg[par[x]]--;
        remov[x] = 1;
        if (deg[par[x]] >= 1) ans--;
      }
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
