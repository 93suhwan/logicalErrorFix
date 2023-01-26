#include <bits/stdc++.h>
using namespace std;
const long long N = 105, MOD = 1e9 + 7;
vector<vector<long long>> adj;
map<long long, map<long long, long long>> cnt;
long long fact[N], dep[N], ans, vis[N], mul[N], mxdep[N];
long long n, k;
void init() {
  fact[0] = 1;
  for (long long i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
}
long long fastpow(long long n, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = res * n % MOD;
    n = n * n % MOD;
    p >>= 1;
  }
  return res;
}
long long nCr(long long n, long long r) {
  if (n < r) return 0;
  return fact[n] * fastpow(fact[n - r], MOD - 2) % MOD *
         fastpow(fact[r], MOD - 2) % MOD;
}
void dfs(long long u, long long p, long long head, long long root) {
  mxdep[u] = 1;
  if (p != -1) cnt[head][dep[u]]++;
  for (auto v : adj[u]) {
    if (v == p) continue;
    dep[v] = dep[u] + 1;
    if (u == root)
      dfs(v, u, v, root);
    else
      dfs(v, u, head, root);
    mxdep[u] = max(mxdep[v] + 1, mxdep[u]);
  }
}
void solve() {
  cin >> n >> k;
  adj.clear();
  adj.resize(n + 1);
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans = 0;
  if (k == 2) {
    ans = nCr(n, 2);
  } else {
    for (long long i = 1; i <= n; i++) {
      cnt.clear();
      fill(vis, vis + N, 0);
      fill(mul, mul + N, 1);
      fill(mxdep, mxdep + N, 0);
      dep[i] = 0;
      dfs(i, -1, i, i);
      for (auto v : adj[i]) {
        for (auto [a, b] : cnt[v]) {
          mul[a] = mul[a] * b % MOD;
        }
      }
      long long cnt2 = 0;
      for (long long j = 100; j; j--) {
        for (auto v : adj[i]) {
          if (mxdep[v] == j) cnt2++;
        }
        ans = (ans + nCr(cnt2, k) * mul[j] % MOD) % MOD;
      }
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  long long t;
  cin >> t;
  while (t--) solve();
}
