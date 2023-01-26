#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7, c;
vector<vector<long long> > d(110);
vector<bool> u(110);
long long dfs(long long v, long long dist, long long pr) {
  u[v] = 1;
  if (!dist) {
    return 1;
  }
  long long m = 0;
  vector<long long> t;
  long long cc = 0;
  for (long long i = 0; i < d[v].size(); i++)
    if (!u[d[v][i]]) {
      long long b = dfs(d[v][i], dist - 1, pr);
      cc += bool(b);
      m += b;
      if (v == pr && b) t.push_back(b);
    }
  c = cc;
  if (v == pr) {
    long long y = 1;
    for (long long i = 0; i < t.size(); i++) y = y * t[i] % mod;
    return y;
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
      for (long long h = 0; h < n; h++) u[h] = 0;
      long long y = dfs(i, j, i);
      m = c;
      if (m >= k) {
        long long ans1 = y;
        for (long long h = m - k + 1; h <= m; h++) ans1 = 1ll * ans1 * h % mod;
        ans = (ans + ans1) % mod;
      }
    }
  }
  for (long long h = 2; h <= k; h++) ans = 1ll * ans * f(h) % mod;
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
