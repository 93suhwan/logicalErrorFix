#include <bits/stdc++.h>
using namespace std;
const long long Mod = (long long)1e9 + 7;
const long long MAXFAC = (long long)2e6 + 10;
long long fac[MAXFAC];
inline long long pw(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1ll) res = res * x % Mod;
    x = x * x % Mod;
    y /= 2;
  }
  return res;
}
void init_fac(long long maxn = MAXFAC) {
  fac[0] = 1;
  for (long long i = 1; i < maxn; ++i) {
    fac[i] = fac[i - 1] * i % Mod;
  }
}
inline long long inv(long long x) { return pw(x, Mod - 2); };
inline long long choose(long long n, long long r) {
  return fac[n] * (inv(fac[n - r]) * inv(fac[r]) % Mod) % Mod;
}
void preproc() { init_fac(110); }
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<vector<long long>> g(n + 1);
  for (long long e = 1; e <= n - 1; ++e) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (k == 2) {
    cout << choose(n, 2) << '\n';
    return;
  }
  vector<vector<long long>> f(n + 1, vector<long long>(n + 1));
  vector<vector<long long>> h(n + 1, vector<long long>(n + 1));
  function<void(long long, long long)> dfs_f = [&](long long u, long long pr) {
    f[u][0] = 1;
    for (auto it = g[u].begin(); it != g[u].end(); ++it)
      if (*it == pr) {
        g[u].erase(it);
        break;
      }
    for (long long v : g[u])
      if (v != pr) {
        dfs_f(v, u);
        for (long long d = 1; d <= n; ++d) f[u][d] += f[v][d - 1];
      }
  };
  dfs_f(1, 0);
  function<void(long long)> dfs_g = [&](long long u) {
    h[u][0] = 1;
    long long childs = (long long)g[u].size();
    vector<vector<long long>> pref(childs, vector<long long>(n + 1));
    vector<vector<long long>> suff(childs, vector<long long>(n + 1));
    for (long long i = 0; i < childs; ++i) {
      long long vi = g[u][i];
      long long rev_i = childs - i - 1;
      long long rev_vi = g[u][rev_i];
      for (long long d = 0; d <= n; ++d) {
        pref[i][d] = f[vi][d] + (i - 1 >= 0 ? pref[i - 1][d] : 0ll);
        suff[rev_i][d] =
            f[rev_vi][d] + (rev_i + 1 <= childs - 1 ? suff[rev_i + 1][d] : 0ll);
      }
    }
    for (long long i = 0; i < childs; ++i) {
      long long vi = g[u][i];
      for (long long d = 1; d <= n; ++d) {
        h[vi][d] += h[u][d - 1];
        if (d - 2 >= 0 and i - 1 >= 0) h[vi][d] += pref[i - 1][d - 2];
        if (d - 2 >= 0 and i + 1 <= childs - 1) h[vi][d] += suff[i + 1][d - 2];
      }
    }
    for (long long v : g[u]) dfs_g(v);
  };
  dfs_g(1);
  long long res = 0;
  for (long long u = 1; u <= n; ++u) {
    long long neigh = (long long)g[u].size() + (u != 1);
    if (neigh < k) continue;
    for (long long d = 1; d <= n; ++d) {
      vector<long long> a;
      if (h[u][d] > 0) a.push_back(h[u][d]);
      for (long long v : g[u])
        if (f[v][d - 1] > 0) a.push_back(f[v][d - 1]);
      if ((long long)a.size() < k) break;
      long long sz = (long long)a.size();
      vector<vector<long long>> dp(sz + 1, vector<long long>(k + 1));
      for (long long i = 0; i <= sz; ++i) dp[i][0] = 1;
      for (long long vk = 1; vk <= k; ++vk)
        for (long long i = 1; i <= sz; ++i)
          dp[i][vk] = (dp[i - 1][vk] + dp[i - 1][vk - 1] * a[i - 1]) % Mod;
      res = (res + dp[sz][k]) % Mod;
    }
  }
  res = (res) % Mod;
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  preproc();
  long long tc = 1;
  cin >> tc;
  for (long long Tt = 1; Tt <= tc; ++Tt) {
    solve();
  }
  return EXIT_SUCCESS;
}
