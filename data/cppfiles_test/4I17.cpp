#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
using namespace std;
const long long N = 2e5 + 100, inf = (long long long long)1e12;
vector<pair<long long long long, long long long long> > g[N];
long long long long a[N];
long long long long sz[N];
long long long long vis[N];
long long long long n, k;
long long long long mod = 1e9 + 7;
long long long long power(long long long long n, long long long long k) {
  if (k == 0) return 1;
  if (k % 2 == 1) {
    long long long long x = power(n, k / 2);
    return x * x % mod * n % mod;
  }
  long long long long x = power(n, k / 2);
  return x * x % mod;
}
void dfssz(long long long long v, long long long long p) {
  sz[v] = 1;
  for (auto U : g[v]) {
    long long long long u = U.first;
    if (u == p || vis[u]) continue;
    dfssz(u, v);
    sz[v] += sz[u];
  }
}
long long long long findcen(long long long long v, long long long long p,
                            long long long long tras) {
  for (auto U : g[v]) {
    long long long long u = U.first;
    if (u == p || vis[u]) continue;
    if (sz[u] >= (tras + 1) / 2) return findcen(u, v, tras);
  }
  return v;
}
long long long long ans = 0;
vector<pair<long long long long, long long long long> > b[2];
void dfs(long long long long v, long long long long p, long long long long t,
         long long long long e, long long long long sig) {
  sig += a[v];
  sig %= mod;
  b[e].push_back({t, sig});
  for (auto U : g[v]) {
    long long long long u = U.first;
    if (vis[u] || u == p) continue;
    if (U.second != e) {
      dfs(u, v, t + 1, U.second, sig);
    } else
      dfs(u, v, t, e, sig);
  }
}
long long long long parw[N];
long long long long parb[N];
long long long long shombol(long long long long cen, bool pp) {
  long long long long jav = 0;
  sort(b[0].begin(), b[0].end());
  sort(b[1].begin(), b[1].end());
  if (b[0].size()) parw[0] = b[0][0].second;
  if (b[1].size()) parb[0] = b[1][0].second;
  for (long long i = 1; i < b[0].size(); i++) {
    parw[i] = parw[i - 1] + b[0][i].second;
    parw[i] %= mod;
  }
  for (long long i = 1; i < b[1].size(); i++) {
    parb[i] = parb[i - 1] + b[1][i].second;
    parb[i] %= mod;
  }
  for (auto u : b[0]) {
    if (u.first <= k) jav += 2 * (u.second + a[cen]) * pp % mod;
    long long long long z =
        upper_bound(b[0].begin(), b[0].end(),
                    pair<long long long long, long long long long>(
                        {k - u.first, inf})) -
        b[0].begin();
    z--;
    if (z >= 0) {
      jav += (u.second + a[cen]) * (z + 1) % mod + parw[z];
    }
    z = upper_bound(b[1].begin(), b[1].end(),
                    pair<long long long long, long long long long>(
                        {k - u.first - 1, inf})) -
        b[1].begin();
    z--;
    if (z >= 0) {
      jav += (u.second + a[cen]) * (z + 1) % mod + parb[z];
    }
    jav %= mod;
  }
  for (auto u : b[1]) {
    if (u.first <= k) jav += 2 * (u.second + a[cen]) * pp % mod;
    long long long long z =
        upper_bound(b[1].begin(), b[1].end(),
                    pair<long long long long, long long long long>(
                        {k - u.first, inf})) -
        b[1].begin();
    z--;
    if (z >= 0) {
      jav += (u.second + a[cen]) * (z + 1) % mod + parb[z];
    }
    z = upper_bound(b[0].begin(), b[0].end(),
                    pair<long long long long, long long long long>(
                        {k - u.first - 1, inf})) -
        b[0].begin();
    z--;
    if (z >= 0) {
      jav += (u.second + a[cen]) * (z + 1) % mod + parw[z];
    }
    jav %= mod;
  }
  return jav;
}
void solve() {
  queue<long long> q;
  q.push(1);
  while (q.size()) {
    long long long long v = q.front();
    q.pop();
    dfssz(v, v);
    long long long long cen = findcen(v, v, sz[v]);
    b[0].clear();
    b[1].clear();
    for (auto U : g[cen]) {
      long long long long u = U.first;
      if (vis[u]) continue;
      dfs(u, cen, 0, U.second, 0);
    }
    ans += shombol(cen, 1);
    for (auto U : g[cen]) {
      long long long long u = U.first;
      if (vis[u]) continue;
      b[0].clear();
      b[1].clear();
      dfs(u, cen, 0, U.second, 0);
      ans -= shombol(cen, 0);
    }
    ans %= mod;
    ans += mod;
    ans %= mod;
    vis[cen] = 1;
    for (auto U : g[cen]) {
      long long long long u = U.first;
      if (vis[u] == 0) q.push(u);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    ans += 2 * a[i];
    ans %= mod;
  }
  for (long long i = 0; i < n - 1; i++) {
    long long long long u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  solve();
  cout << ans * power(2, mod - 2) % mod << endl;
}
