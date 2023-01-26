#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int buds;
int leafs;
bool dfs(int v, int p) {
  int lfcnt = 0;
  for (int w : g[v]) {
    if (w == p) continue;
    if (!dfs(w, v)) lfcnt++;
  }
  if (lfcnt == 0)
    leafs++;
  else if (v != 1)
    buds++;
  return lfcnt != 0;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int test = 0; test < t; test++) {
    int n, u, v;
    cin >> n;
    g.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    buds = 0;
    leafs = 0;
    dfs(1, 0);
    cout << leafs - buds << "\n";
  }
  return 0;
}
