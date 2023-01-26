#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool rec2(int u, bool cur_val, vector<bool> &vis, vector<bool> &vals,
          vector<vector<array<int, 2>>> &adj2) {
  if (vis[u]) {
    if (cur_val != vals[u]) {
      return 0;
    } else {
      return 1;
    }
  } else {
    vis[u] = 1;
    vals[u] = cur_val;
    for (auto p : adj2[u]) {
      int v = p[0];
      int m = p[1];
      int new_val = cur_val ^ m;
      if (!rec2(v, new_val, vis, vals, adj2)) {
        return 0;
      }
    }
    return 1;
  }
}
bool rec1(int u, vector<bool> &vis, vector<bool> &vals,
          vector<vector<int>> &adj1, vector<vector<array<int, 2>>> &adj2,
          int prev) {
  if (!vis[u]) {
    vals[u] = 0;
    if (!rec2(u, 0, vis, vals, adj2)) {
      return 0;
    }
  }
  for (int i = 0; i < adj1[u].size(); i++) {
    int v = adj1[u][i];
    if (v == prev) {
      continue;
    }
    if (!rec1(v, vis, vals, adj1, adj2, u)) {
      return 0;
    }
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(n - 1);
    vector<vector<int>> adj1(n + 1);
    vector<vector<array<int, 2>>> adj2(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int x, y, v;
      cin >> x >> y >> v;
      edges[i] = {x, y, v};
      adj1[x].push_back(y);
      adj1[y].push_back(x);
      if (v != -1) {
        int v2 = v;
        int cnt = 0;
        while (v2 != 0) {
          if (v2 & 1) {
            cnt++;
          }
          v2 >>= 1;
        }
        cnt %= 2;
        adj2[x].push_back({y, cnt});
        adj2[y].push_back({x, cnt});
      }
    }
    for (int i = 0; i < m; i++) {
      int a, b, p;
      cin >> a >> b >> p;
      adj2[a].push_back({b, p});
      adj2[b].push_back({a, p});
    }
    vector<bool> vis(n + 1, 0);
    vector<bool> vals(n + 1, 0);
    if (!rec1(1, vis, vals, adj1, adj2, -1)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 0; i < n - 1; i++) {
        auto edge = edges[i];
        int a = edge[0], b = edge[1], val = edge[2];
        cout << a << " " << b << " ";
        if (val == -1) {
          val = vals[a] ^ vals[b];
        }
        cout << val << "\n";
      }
    }
  }
}
