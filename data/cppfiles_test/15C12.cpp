#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
const int N = 2e5 + 5;
const long long int mod = 1e9 + 7;
const long long int Mod = 998244353;
const long double Pi = acos(-1);
const long long int Inf = 4e18;
const long double Eps = 1e-9;
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
using namespace std;
long long int d[101][101];
vector<long long int> g[101];
long long int cnt;
void Dfs(long long int t, long long int p, long long int k, long long int src) {
  cnt += (d[src][t] == k);
  for (auto u : g[t]) {
    if (u != p) {
      d[src][u] = d[src][t] + 1;
      Dfs(u, t, k, src);
    }
  }
}
void TestCase() {
  long long int n, k, ans = 0;
  cin >> n >> k;
  for (long long int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(d, 0, sizeof(d));
  if (k == 2)
    cout << (n * (n - 1)) / 2;
  else {
    vector<long long int> take;
    vector<vector<long long int> > dp;
    for (long long int c = 2; c <= 100; c += 2) {
      for (long long int i = 1; i <= n; i++) {
        for (auto x : g[i]) {
          cnt = 0;
          d[i][x] = 1;
          Dfs(x, i, c / 2, i);
          take.push_back(cnt);
        }
        long long int m = (long long int)take.size();
        dp.resize(m + 1);
        for (long long int j = 0; j <= m; j++) dp[j].assign(k + 1, 0);
        dp[0][0] = 1;
        for (long long int j = 1; j <= m; j++) {
          for (long long int u = 0; u <= k; u++) dp[j][u] = dp[j - 1][u];
          for (long long int u = 1; u <= k; u++) {
            dp[j][u] += (dp[j - 1][u - 1] * take[j - 1]) % mod;
            dp[j][u] %= mod;
          }
        }
        ans += dp[m][k];
        ans %= mod;
        take.clear();
      }
    }
    cout << ans;
  }
  for (long long int i = 1; i <= n; i++) g[i].clear();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int T = 1;
  cin >> T;
  while (T--) {
    TestCase();
    cout << "\n";
  }
  return 0;
}
