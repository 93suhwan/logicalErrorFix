#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
const long long MOD = 998244353;
const long long MAXN = 1e5 + 7;
const long long INF = 2e9;
const long long BIG_INF = 2e18;
const long long LOG = 20;
mt19937 engine(chrono::system_clock::now().time_since_epoch().count());
long long n;
vector<vector<long long> > g;
vector<long long> cur;
long long ans = 1;
void dfs(long long v, long long p) {
  if (g[v].size() == 0) {
    cur[v] = 1;
    return;
  }
  long long u_nego = 0;
  for (long long u : g[v]) {
    if (u != p) {
      dfs(u, v);
      u_nego += cur[u];
    }
  }
  if (u_nego == 0) {
    cur[v] = 1;
  } else {
    ans += u_nego - 1;
  }
}
void solve() {
  cin >> n;
  cur.clear();
  cur.resize(n, 0);
  g.clear();
  g.resize(n);
  ans = 1;
  for (long long i = 0; i < n - 1; ++i) {
    long long v, u;
    cin >> v >> u;
    --v, --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  dfs(0, -1);
  cout << ans << '\n';
  ;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
