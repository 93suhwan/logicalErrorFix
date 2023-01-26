#include <bits/stdc++.h>
using namespace std;
long long maxn = 2 * 1e5 + 10;
long long n;
vector<vector<long long>> edges;
long long dfs(long long v, long long p) {
  long long ret = 0, buds = 0, leaf = 0;
  for (long long to : edges[v]) {
    if (to == p) continue;
    if (edges[to].size() == 1) {
      ret++;
      leaf++;
    } else {
      ret += dfs(to, v);
      buds++;
    }
  }
  if (leaf > 0) {
    return ret - buds;
  } else {
    return ret - max(0ll, buds - 1);
  }
}
long long solve() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    edges[i].clear();
  }
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    a--, b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  cout << dfs(0, -1) << "\n";
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  edges.resize(maxn);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
