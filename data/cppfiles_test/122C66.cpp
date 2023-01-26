#include <bits/stdc++.h>
#pragma GCC optimize("trapv")
using namespace std;
long long dx[] = {0, 1, 0, -1};
long long dy[] = {1, 0, -1, 0};
const long long mod = 998244353;
const long long INF = LLONG_MAX / 4;
const long long maxn = 1000007;
const double EPS = 1e-9;
long long _;
long long n, m;
vector<tuple<long long, long long, long long>> edges;
vector<pair<long long, long long>> g[maxn];
bool vis[maxn];
long long col[maxn];
bool ok = 1;
void dfs(long long u, long long c) {
  if (vis[u]) {
    if (c != col[u]) ok = 0;
    return;
  }
  col[u] = c, vis[u] = 1;
  for (auto [x, w] : g[u]) {
    dfs(x, c ^ w);
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> _;
  while (_--) {
    cin >> n >> m;
    edges.clear();
    for (long long i = 1; i <= (long long)(n); ++i)
      g[i].clear(), vis[i] = 0, col[i] = 0;
    for (long long i = 0; i < (long long)(n - 1); ++i) {
      long long u, v, w;
      cin >> u >> v >> w;
      edges.push_back({u, v, w});
      if (w == -1) continue;
      if (__builtin_popcount(w) & 1)
        g[u].push_back({v, 1}), g[v].push_back({u, 1});
      else
        g[u].push_back({v, 0}), g[v].push_back({u, 0});
    }
    for (long long i = 0; i < (long long)(m); ++i) {
      long long u, v, w;
      cin >> u >> v >> w;
      if (__builtin_popcount(w) & 1)
        g[u].push_back({v, 1}), g[v].push_back({u, 1});
      else
        g[u].push_back({v, 0}), g[v].push_back({u, 0});
    }
    ok = 1;
    for (long long i = 1; i <= (long long)(n); ++i) {
      if (vis[i]) continue;
      dfs(i, 0);
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (auto [u, v, w] : edges) {
      if (w != -1)
        cout << u << " " << v << " " << w << "\n";
      else
        cout << u << " " << v << " " << (col[u] ^ col[v]) << "\n";
    }
  }
  return 0;
}
