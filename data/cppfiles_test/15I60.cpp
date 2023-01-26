#include <bits/stdc++.h>
using namespace std;
long long cil(long long x, long long y) {
  if (x % y == 0) {
    return x / y;
  };
  return x / y + 1;
}
const int32_t mod = 1e9 + 7;
long long power(long long a, long long b) {
  long long ans = 1;
  a %= mod;
  while (b > 0) {
    if (b % 2) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    b /= 2;
  }
  return ans;
}
long long modi(long long a) { return power(a, mod - 2); }
const int32_t MXN = 1e5 + 5;
long long factorial[MXN + 1];
long long make_factorial() {
  factorial[0] = 1;
  for (long long i = 1; i <= MXN; i++) {
    factorial[i] = i * factorial[i - 1];
    factorial[i] %= mod;
  }
  return 0;
}
long long ncr(long long n, long long r) {
  if (n < r) return 0;
  long long ans = factorial[n];
  ans %= mod;
  ans *= modi(factorial[r]);
  ans %= mod;
  ans *= modi(factorial[n - r]);
  ans %= mod;
  return ans;
}
const int32_t N = 101;
vector<long long> dep[N];
long long root;
vector<long long> adj[N];
long long dfs(long long v, long long pre) {
  long long maxa = 0;
  for (auto u : adj[v]) {
    if (u == pre) continue;
    long long d = dfs(u, v);
    if (v == root) dep[v].push_back(d);
    maxa = max(maxa, d);
  }
  return maxa + 1;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    adj[i].clear();
    dep[i].clear();
  }
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (long long i = 1; i <= n; i++) {
    root = i;
    dfs(root, 0);
  }
  long long ans = 0;
  if (k == 2) {
    ans = ncr(n, 2);
    cout << ans << '\n';
    return;
  }
  for (long long i = 1; i <= n; i++) {
    sort(dep[i].begin(), dep[i].end());
    for (long long d = 2; d <= n; d += 2) {
      long long tot = (long long)(dep[i]).size();
      long long need =
          lower_bound((dep[i]).begin(), (dep[i]).end(), d / 2) - dep[i].begin();
      need = tot - need;
      if (need < k) continue;
      ans += ncr(need, k);
      ans %= mod;
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  make_factorial();
  long long tt = 1;
  cin >> tt;
  for (long long tc = 1; tc <= tt; tc++) {
    solve();
  }
  return 0;
}
