#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 7;
const int MOD = 998244353;
int t;
int n;
vector<int> G[MAX];
int f[MAX], k;
bool dfs(int u, int fa) {
  f[u] = 0;
  if (u != 1 && G[u].size() == 1) return true;
  for (auto v : G[u]) {
    if (v == fa) continue;
    if (dfs(v, u)) f[u]++;
  }
  if (fa && f[u] % k != 0) {
    f[u]++;
    return false;
  }
  return true;
}
int qw[MAX];
int ans[MAX];
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  qw[0] = 1;
  for (int i = 1; i <= 100000; i++) qw[i] = qw[i - 1] * 2 % MOD;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) G[i].clear(), ans[i] = 0;
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v), G[v].push_back(u);
    }
    ans[1] = qw[n - 1];
    for (int i = 2; i < n; i++) {
      if ((n - 1) % i != 0) continue;
      k = i;
      dfs(1, 0);
      int fg = 0;
      for (int j = 1; j <= n; j++)
        if (f[j] % i) {
          fg = 1;
          break;
        }
      if (!fg) ans[i]++;
    }
    for (int i = n; i >= 1; i--) {
      for (int j = 2 * i; j <= n; j += i) ans[i] -= ans[j];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';
  }
  return 0;
}
