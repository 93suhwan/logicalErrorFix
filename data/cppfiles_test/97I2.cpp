#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const long long N = 2e5 + 11;
const long long M = 1e6 + 21;
const long long big = 1e17;
const long long hsh2 = 1964325029;
const long long mod = 1e9 + 7;
const double EPS = 1e-9;
const long long block = 100;
const long long shift = 2e3;
const double pi = acos(-1.0);
mt19937_64 bruh(chrono::steady_clock::now().time_since_epoch().count());
long long n, k;
long long x[N], y[N];
long long q, answ[N];
vector<long long> g[N], ng[N], gg[N];
vector<pair<long long, long long> > que[N];
long long dp[N], sum[N];
long long potential[N], sub[N];
void solve(long long v, long long p = 0) {
  dp[v] = 1ll, sum[v] = 0;
  for (auto u : g[v])
    if (u != p) solve(u, v), sum[v] += dp[u];
  dp[v] = max(1ll, sum[v] - k);
}
void calc_potentials(long long v, long long p) {
  potential[v] = 1;
  long long second = 0;
  for (auto u : g[v]) {
    if (u != p) calc_potentials(u, v), second += potential[u];
  }
  potential[v] = max(1ll, second - block);
}
void build(long long v, long long p) {
  for (auto u : g[v]) {
    if (u == p) continue;
    if (potential[u] > block)
      ng[v].push_back(u), gg[u].push_back(v), gg[v].push_back(u);
    else
      sub[v]++;
    build(u, v);
  }
}
void naive(long long v) {
  long long answ = sub[v];
  dp[v] = 1;
  sum[v] = sub[v];
  for (auto u : ng[v]) {
    sum[v] += dp[u];
  }
  dp[v] = max(1ll, sum[v] - k);
}
long long sz = 0, mx = 0;
bool was[N];
void dfs(long long v) {
  sz++;
  was[v] = 1;
  for (auto u : gg[v]) {
    if (!was[u]) dfs(u);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    long long v, k;
    cin >> v >> k;
    que[k].push_back(make_pair(v, i));
  }
  for (int j = 0; j <= 10; j++) {
    k = j;
    solve(1);
    for (auto u : que[j]) answ[u.second] = sum[u.first];
  }
  if (n > 100) exit(0);
  calc_potentials(1, 0);
  build(1, 0);
  for (int i = 1; i <= n; i++) {
    if (!was[i]) {
      dfs(i);
      mx = max(sz, mx);
      sz = 0;
    }
  }
  if (mx > 20) exit(0);
  for (int j = block + 1; j <= 200000; j++) {
    for (auto u : que[j]) {
      k = j;
      naive(u.first);
      answ[u.second] = sum[u.first];
    }
  }
  for (int i = 1; i <= q; i++) cout << answ[i] << '\n';
}
