#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7, mod = 1e9 + 7;
long long dp[105][105], ans;
vector<int> G[105], d;
int n, k, mx;
void dfs(int x, int f, int dep) {
  ++d[dep];
  if (dep > mx) mx = dep;
  for (int i : G[x]) {
    if (i == f) continue;
    dfs(i, x, dep + 1);
  }
}
inline void solve() {
  cin >> n >> k;
  ans = 0;
  for (int i = 1; i <= n; ++i) G[i].clear();
  for (int i = 2, x, y; i <= n; ++i) {
    cin >> x >> y;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }
  if (k == 2) {
    cout << n * (n - 1) / 2 << '\n';
    return;
  }
  vector<int> t(n + 1);
  for (int root = 1; root <= n; ++root) {
    vector<vector<int> > v;
    mx = 0;
    for (int x : G[root]) {
      d = t;
      dfs(x, root, 1);
      v.emplace_back(d);
    }
    int m = v.size();
    if (m < k) continue;
    for (int i = 1; i <= mx; ++i) {
      vector<int> p;
      int q = 0;
      for (auto &x : v) p.emplace_back(x[i]), q |= x[i];
      if (!q) break;
      for (int j = 1; j <= m; ++j)
        for (int x = 0; x <= k; ++x) dp[j][x] = 0;
      dp[0][0] = 1;
      for (int j = 1; j <= m; ++j) {
        for (int x = 0; x <= k; ++x) dp[j][x] = dp[j - 1][x];
        for (int x = 1; x <= k; ++x)
          dp[j][x] = (dp[j][x] + dp[j - 1][x - 1] * p[j - 1]) % mod;
      }
      ans = (ans + dp[m][k]) % mod;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) solve();
  return 0;
}
