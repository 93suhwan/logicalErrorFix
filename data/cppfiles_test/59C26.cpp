#include <bits/stdc++.h>
int a[1024], b[1024];
std::vector<int> node[1024];
int que[1024];
int nq;
int par[1024];
int stat[1024];
long long int val[1024], gval;
void set_stat(int u) {
  while (stat[u] == 1) stat[u] = 2, u = par[u];
}
int solve(int k) {
  b[0] = k;
  memset(stat, 0, sizeof(stat));
  stat[0] = 2, que[0] = 0, nq = 1;
  bool f = true;
  while (f) {
    gval = 0;
    for (int i = 0; i < nq; ++i) {
      int u = que[i];
      if (stat[u] == 1)
        val[u] = val[par[u]] + b[u];
      else
        assert(stat[u] == 2), val[u] = 0, gval += b[u];
    }
    f = false;
    for (int i = 0; i < nq; ++i) {
      int u = que[i];
      for (const int &v : node[u])
        if (v != par[u]) {
          if (stat[v] == 0 && gval + val[u] > a[v])
            stat[v] = 1, par[v] = u, que[nq++] = v, val[v] = val[u] + b[v],
            f = true;
          else if ((stat[v] == 1 || stat[u] == 1) && par[v] != u &&
                   gval + val[u] > a[v])
            set_stat(u), set_stat(v), f = true;
        }
    }
  }
  return nq;
}
int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; ++tc) {
    for (int i = 0; i < 1024; ++i) node[i].clear();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v), --u, --v;
      node[u].push_back(v);
      node[v].push_back(u);
    }
    int ans = -1;
    for (int i = 1 << 30; i; i >>= 1) {
      int t = ans + i;
      if (solve(t) != n) ans = t;
    }
    ++ans;
    printf("%d\n", ans);
  }
  return 0;
}
