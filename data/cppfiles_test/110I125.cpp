#include <bits/stdc++.h>
using namespace std;
bool topo(vector<vector<int>> &adj, vector<int> &vis, int u) {
  vis[u] = 1;
  for (int v : adj[u]) {
    if (vis[v] == 0) {
      if (!topo(adj, vis, v)) return false;
    } else if (vis[v] == 1) {
      return false;
    }
  }
  vis[u] = 2;
  return true;
}
int main() {
  int t, n, k, a, hc;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vector<vector<int>> adj(n + 1);
    vector<int> h(n + 1, 1), v(n + 1, 0);
    hc = n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &k);
      if (k) h[i] = 0, --hc;
      while (k--) {
        scanf("%d", &a);
        adj[a].push_back(i);
      }
    }
    bool Topo = (hc > 0);
    for (int i = 1; Topo && i <= n; ++i) {
      if (h[i]) Topo &= topo(adj, v, i);
    }
    if (Topo) {
      set<int> s;
      int c = 0;
      for (int i = 1; i <= n; ++i)
        if (h[i]) s.insert(i);
      for (; s.size(); ++c) {
        int d = 0;
        while (s.upper_bound(d) != s.end()) {
          d = *(s.upper_bound(d));
          s.erase(d);
          for (int x : adj[d]) s.insert(x);
        }
      }
      printf("%d\n", c);
    } else {
      puts("-1");
    }
  }
}
