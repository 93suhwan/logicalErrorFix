#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2")
using namespace std;
mt19937 mrnd(time(0));
const int INF = 1000000007;
const long long INF_LL = 1152921504606846977;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[v].insert(u);
    g[u].insert(v);
  }
  set<int> dead;
  for (int i = 0; i < n; ++i) {
    if (!g[i].empty() && *g[i].rbegin() > i) {
      dead.insert(i);
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int z;
    cin >> z;
    if (z == 1) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].insert(v);
      g[v].insert(u);
      if (!g[u].empty() && *g[u].rbegin() > u) {
        dead.insert(u);
      }
      if (!g[v].empty() && *g[v].rbegin() > v) {
        dead.insert(v);
      }
      if (g[u].empty() || *g[u].rbegin() < u) {
        dead.erase(u);
      }
      if (g[v].empty() || *g[v].rbegin() < v) {
        dead.erase(v);
      }
    } else if (z == 2) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].erase(v);
      g[v].erase(u);
      if (!g[u].empty() && *g[u].rbegin() > u) {
        dead.insert(u);
      }
      if (!g[v].empty() && *g[v].rbegin() > v) {
        dead.insert(v);
      }
      if (g[u].empty() || *g[u].rbegin() < u) {
        dead.erase(u);
      }
      if (g[v].empty() || *g[v].rbegin() < v) {
        dead.erase(v);
      }
    } else {
      cout << n - int(dead.size()) << '\n';
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(20);
  int tests = 1;
  while (tests--) {
    solve();
  }
}
