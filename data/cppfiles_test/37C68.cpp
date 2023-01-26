#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
using namespace std;
const long long N = 1e5 + 100;
vector<long long> p[N];
vector<long long> g[N];
long long long long ans[N];
long long long long mod = 998244353;
long long long long dp[N];
long long long long vis[N];
long long long long fac[N];
long long long long fm[N];
long long long long sz[N];
long long long long power(long long long long n, long long long long k) {
  if (k == 0) return 1;
  if (k % 2 == 1) {
    long long long long x = power(n, k / 2);
    return x * x % mod * n % mod;
  }
  long long long long x = power(n, k / 2);
  return x * x % mod;
}
long long long long ent(long long long long k, long long long long n) {
  if (k < 0 || k > n) return 0;
  if (k == 0 || k == n) return 1;
  return fac[n] * fm[k] % mod * fm[n - k] % mod;
}
void dfs(long long long long v, long long long long p, long long long long x) {
  sz[v] = 1;
  vis[v] = 0;
  long long long long z = g[v].size();
  long long long long p1 = 0, p2 = 0;
  for (auto u : g[v]) {
    if (u == p) continue;
    dfs(u, v, x);
    if (vis[u])
      z--, p1++;
    else
      p2++;
    sz[v] += sz[u];
  }
  if (z % x == 0) vis[v] = 1;
  if (z % x > 1) {
    dp[v] = 0;
    return;
  }
  dp[v] = 1;
  long long long long jj = sz[v];
  for (auto u : g[v]) {
    if (u == p) continue;
    dp[v] *= dp[u];
    dp[v] %= mod;
  }
}
long long Main() {
  long long long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    g[i].clear();
    ans[i] = 0;
  }
  for (long long i = 0; i < n - 1; i++) {
    long long long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ans[1] = 1;
  for (long long i = 1; i < n; i++) ans[1] = ans[1] * 2 % mod;
  long long long long id = 1;
  for (long long i = 1; i <= n; i++) {
    if (g[i].size() == 1) continue;
    long long long long p1 = 0;
    for (auto u : g[i]) {
      if (g[u].size() > 1) p1++;
    }
    if (p1 <= 1) {
      id = g[i].size();
    }
  }
  for (auto u : p[id]) {
    dfs(1, 1, u);
    ans[u] = dp[1];
    if (vis[1] == 0) ans[u] = 0;
  }
  for (auto u : p[id - 1]) {
    dfs(1, 1, u);
    ans[u] = dp[1];
    if (vis[1] == 0) ans[u] = 0;
  }
  for (long long i = n; i; i--) {
    for (long long j = i + i; j <= n; j += i) {
      ans[i] -= ans[j];
      ans[i] += mod;
      ans[i] %= mod;
    }
  }
  for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fac[0] = 1;
  fm[0] = 1;
  for (long long i = 1; i < N; i++) {
    fac[i] = fac[i - 1] * i % mod;
    fm[i] = power(fac[i], mod - 2);
  }
  for (long long i = 2; i < N; i++) {
    for (long long j = i; j < N; j += i) p[j].push_back(i);
  }
  long long long long t = 1;
  cin >> t;
  while (t--) Main();
}
