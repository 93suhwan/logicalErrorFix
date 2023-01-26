#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
vector<vector<long long> > d(110);
vector<bool> u(110);
vector<long long> t;
long long dfs(long long v, long long dist, long long pr) {
  u[v] = 1;
  if (!dist) {
    return 1;
  }
  long long m = 0;
  for (long long i = 0; i < d[v].size(); i++)
    if (!u[d[v][i]]) {
      long long b = dfs(d[v][i], dist - 1, pr);
      m += b;
      if (v == pr && b) t.push_back(b);
    }
  return m;
}
long long f(long long k) {
  long long m = mod - 2;
  long long a = 1;
  while (m) {
    if (m % 2) a = 1ll * a * k % mod;
    k = 1ll * k * k % mod;
    m /= 2;
  }
  return a;
}
void solve() {
  long long n, m, k, ans = 0;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) d[i].clear();
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    d[u].push_back(v);
    d[v].push_back(u);
  }
  if (k == 1) {
    cout << n << '\n';
    return;
  }
  if (k == 2) {
    cout << n * (n - 1) / 2 << '\n';
    return;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 1; j < n; j++) {
      long long ans1 = 0;
      for (long long h = 0; h < n; h++) u[h] = 0;
      t.clear();
      m = dfs(i, j, i);
      if (t.size() >= k) {
        long long dp[110][110] = {0};
        for (long long j = 0; j < k; j++) {
          long long sum;
          if (!j)
            sum = 1;
          else
            sum = dp[j - 1][j - 1];
          for (long long i = j; i < t.size(); i++) {
            dp[i][j] = 1ll * sum * t[i] % mod;
            sum = (sum + dp[i - 1][j - 1]) % mod;
          }
        }
        for (long long i = 0; i < t.size(); i++)
          ans1 = (ans1 + dp[i][k - 1]) % mod;
        ans = (ans + ans1) % mod;
      }
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
