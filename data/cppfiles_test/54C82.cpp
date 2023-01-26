#include <bits/stdc++.h>
using namespace std;
int t;
int n, m;
int dsu[200100];
set<int> g[200100][2];
const int debug = 55;
int f(int x) {
  if (dsu[x] < 0) return x;
  int r = f(dsu[x]);
  dsu[x] = r;
  return r;
}
bool ok = 1;
int main() {
  cin >> t;
  for (int z = 1; z <= t; z++) {
    cin >> n >> m;
    memset(dsu, -1, sizeof(int) * (n + 10));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < 2; j++) {
        g[i][j].clear();
      }
    }
    for (int i = 1; i <= n; i++) {
      g[i][0].insert(i);
    }
    ok = 1;
    for (int i = 0; i < m; i++) {
      int u, v;
      string s;
      cin >> u >> v >> s;
      bool crew = (s == "crewmate");
      if (ok) {
        if (f(u) == f(v)) {
          int tmp = f(u);
          bool gr_u = g[tmp][1].find(u) != g[tmp][1].end();
          bool gr_v = g[tmp][1].find(v) != g[tmp][1].end();
          if (crew != (gr_u == gr_v)) {
            ok = 0;
          }
        } else {
          if (dsu[f(u)] > dsu[f(v)]) swap(u, v);
          bool gr_u = g[f(u)][1].find(u) != g[f(u)][1].end();
          bool gr_v = g[f(v)][1].find(v) != g[f(v)][1].end();
          if (!crew) gr_v = !gr_v;
          for (auto x : g[f(v)][gr_v]) {
            g[f(u)][gr_u].insert(x);
          }
          for (auto x : g[f(v)][!gr_v]) {
            g[f(u)][!gr_u].insert(x);
          }
          dsu[f(u)] += dsu[f(v)];
          dsu[f(v)] = f(u);
        }
      }
    }
    if (ok) {
      int res = 0;
      for (int i = 1; i <= n; i++) {
        if (dsu[i] < 0) {
          res += (int)max(g[i][0].size(), g[i][1].size());
        }
      }
      cout << res;
    } else {
      cout << -1;
    }
    cout << '\n';
  }
  return 0;
}
