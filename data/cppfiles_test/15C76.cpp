#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const long long inf = 1e9 + 10;
const long long inf2 = 1e18 + 99LL;
const long double inf3 = 1e17;
const long long mod = 1e9 + 7, mod2 = 998244353;
const long double eps = 1e-9;
const bool local = false;
const int logn = 17, maxn = 101, maxm = 200001, maxn2 = 3;
vector<int> g[maxn], d, a[maxn];
void dfs(int v, int p, int cd = 0) {
  d[cd]++;
  for (int x : g[v]) {
    if (x == p) continue;
    dfs(x, v, cd + 1);
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) g[i].clear();
  for (int i = 0; i < n - 1; i++) {
    int ta, b;
    cin >> ta >> b;
    ta--;
    b--;
    g[ta].push_back(b);
    g[b].push_back(ta);
  }
  if (k == 2) {
    cout << n * (n - 1) / 2 << nl;
    return;
  }
  long long ans = 0;
  for (int v = 0; v < n; v++) {
    if ((int)((g[v]).size()) < k) continue;
    for (int i = 0; i < n; i++) a[i].clear();
    for (int x : g[v]) {
      d.assign(n, 0);
      dfs(x, v);
      for (int j = 0; j < n; j++) {
        if (d[j] == 0) break;
        a[j].push_back(d[j]);
      }
    }
    for (int i = 0; i < n; i++) {
      if ((int)((a[i]).size()) < k) break;
      vector<vector<long long>> dp((int)((a[i]).size()) + 1,
                                   vector<long long>(k + 1));
      dp[0][0] = 1;
      for (int j = 1; j <= (int)((a[i]).size()); j++) {
        dp[j][0] = dp[j - 1][0];
        for (int tk = 1; tk <= k; tk++) {
          dp[j][tk] = dp[j - 1][tk - 1] * a[i][j - 1] + dp[j - 1][tk];
          dp[j][tk] %= mod;
        }
      }
      ans += dp.back().back();
      ans %= mod;
    }
  }
  cout << ans << nl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
