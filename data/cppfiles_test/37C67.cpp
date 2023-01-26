#include <bits/stdc++.h>
using namespace std;
const long long nax = 3e5 + 10, mod = 998244353;
vector<long long> g[nax];
long long dp[nax], n, d, ok, res[nax];
void dfs(long long s, long long p = 0) {
  if (!ok) return;
  for (auto it : g[s])
    if (it ^ p) dfs(it, s);
  if (dp[s] % d != 0) {
    if (p) dp[s]++;
    if (dp[s] % d != 0) {
      ok = 0;
      return;
    }
  } else
    dp[p]++;
}
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) dp[i] = res[i] = 0, g[i].clear();
    for (long long i = 1; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    res[1] = 1;
    for (long long i = 1; i <= n - 1; i++) res[1] = (2 * res[1]) % mod;
    for (d = 2; d <= n - 1; d++)
      if ((n - 1) % d == 0) {
        ok = 1;
        dfs(1);
        res[d] = ok;
        for (long long i = 0; i <= n; i++) dp[i] = 0;
      }
    for (long long i = n; i >= 1; i--)
      for (long long j = 2 * i; j <= n; j += i)
        res[i] = (res[i] - res[j] + mod) % mod;
    for (long long i = 1; i <= n; i++) cout << res[i] << ' ';
    cout << '\n';
  }
  return 0;
}
