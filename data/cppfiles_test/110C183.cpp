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
  int t, n, k, a;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vector<vector<int>> adj(n + 1);
    vector<int> p(n + 1, 0), v(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &k);
      while (k--) {
        scanf("%d", &a);
        adj[a].push_back(i);
        p[i]++;
      }
    }
    bool Topo = true;
    for (int i = 1; Topo && i <= n; ++i) {
      if (v[i] == 0) Topo &= topo(adj, v, i);
    }
    if (Topo) {
      set<int> s;
      int c = 0;
      for (int i = 1; i <= n; ++i)
        if (!p[i]) s.insert(i);
      for (; s.size(); ++c) {
        int d = 0;
        while (s.upper_bound(d) != s.end()) {
          d = *(s.upper_bound(d));
          s.erase(d);
          for (int x : adj[d]) {
            if (--p[x] == 0) s.insert(x);
          }
        }
      }
      printf("%d\n", c);
    } else {
      puts("-1");
    }
  }
}
