#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> adj;
vector<long long> type;
void dfs(long long s, long long p) {
  bool leaves = false;
  for (auto &u : adj[s]) {
    if (u != p) {
      dfs(u, s);
      if (type[u] == 1) leaves = true;
    }
  }
  if (!leaves)
    type[s] = 1;
  else
    type[s] = 2;
}
void solve() {
  adj.clear();
  long long n, k = 0;
  cin >> n;
  adj.resize(n + 1);
  type.assign(n + 1, -1);
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  type[1] = 0;
  dfs(1, -1);
  bool root_leaves = false;
  for (long long i = 2; i <= n; i++) {
    if (type[i] == 2) k++;
  }
  for (long long i : adj[1])
    if (type[i] == 1) root_leaves = true;
  cout << n - 2 * k - root_leaves << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) solve();
  return 0;
}
