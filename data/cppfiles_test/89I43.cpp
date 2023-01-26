#include <bits/stdc++.h>
using namespace std;
long long maxn = 2 * 1e5 + 10;
long long n;
vector<vector<long long>> edges;
vector<long long> b;
long long buds = 0;
void dfs(long long v, long long p) {
  long long f = (edges[v].size() >= 2);
  for (long long to : edges[v]) {
    if (to == p) continue;
    dfs(to, v);
    if (edges[to].size() - b[to] != 1) {
      f = 0;
    }
  }
  if (f && v != 0) {
    buds++;
    b[p]++;
  }
}
long long solve() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    edges[i].clear();
    b[i] = 0;
  }
  buds = 0;
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    u--, v--;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  long long all_leaves = 0, leaves0 = 0;
  for (long long i = 1; i < n; i++) {
    all_leaves += (edges[i].size() == 1);
    if (edges[i].size() == 1 && edges[i][0] == 0) leaves0++;
  }
  dfs(0, -1);
  if (leaves0 > 0) {
    cout << all_leaves - buds << "\n";
  } else {
    cout << all_leaves - max(0ll, buds - 1) << "\n";
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  edges.resize(maxn);
  b.resize(maxn);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
