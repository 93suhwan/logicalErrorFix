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
long long n, k;
vector<long long> adj[N];
long long sol(vector<long long>& a) {
  if ((long long)(a).size() < k) return 0;
  long long m = (long long)(a).size();
  vector<vector<long long> > dp(m + 1, vector<long long>(k + 1, 0));
  dp[0][0] = 1;
  for (long long i = 1; i <= m; i++) {
    for (long long j = 1; j <= i; j++) {
      if (j > k) break;
      dp[i][j] = dp[i - 1][j - 1] * a[i - 1] + dp[i - 1][j];
      dp[i][j] %= mod;
    }
  }
  return dp[m][k];
}
long long dfs(long long v, long long pre, long long curr, long long tar) {
  if (curr == tar) return 1;
  long long cnt = 0;
  for (auto u : adj[v]) {
    if (u == pre) continue;
    long long d = dfs(u, v, curr + 1, tar);
    cnt += d;
  }
  return cnt;
}
long long calc(long long root) {
  vector<long long> a[n + 1];
  for (long long i = 1; i <= n; i++) {
    for (auto u : adj[root]) {
      long long x = dfs(u, root, 0, i - 1);
      a[i].push_back(x);
    }
  }
  long long ans = 0;
  for (long long d = 1; d <= n; d++) {
    ans += sol(a[d]);
    ans %= mod;
  }
  return ans;
}
void solve() {
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    adj[i].clear();
  }
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  long long ans = 0;
  if (k == 2) {
    ans = ncr(n, 2);
    cout << ans << '\n';
    return;
  }
  for (long long i = 1; i <= n; i++) {
    ans += calc(i);
    ans %= mod;
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
