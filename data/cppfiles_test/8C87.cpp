#include <bits/stdc++.h>
using namespace std;
vector<int> e[100010];
int d[100010], in[100010], out[100010], c;
int par[18][100010];
void dfs(int v, int p = -1) {
  in[v] = ++c;
  for (int i = 0; i < e[v].size(); i++) {
    int w = e[v][i];
    if (p == w) continue;
    par[0][w] = v;
    d[w] = d[v] + 1;
    dfs(w, v);
  }
  out[v] = ++c;
}
long long b[200010];
void add(int p, int v) {
  while (p < 200010) {
    b[p] += v;
    p += p & -p;
  }
}
long long sum(int p) {
  long long res = 0;
  while (p) {
    res += b[p];
    p -= p & -p;
  }
  return res;
}
int lca(int u, int v) {
  if (d[u] > d[v]) return lca(v, u);
  int dd = d[v] - d[u];
  for (int i = 0; i < 17; i++) {
    if (dd >> i & 1) {
      v = par[i][v];
    }
  }
  if (u == v) return u;
  for (int i = 16; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][u];
}
int a[100010];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] < 0) a[i] = -a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u;
    --v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(0);
  for (int i = 0; i < n; i++) {
    add(in[i], a[i]);
    add(out[i], -a[i]);
  }
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < n; j++) {
      par[i + 1][j] = par[i][par[i][j]];
    }
  }
  while (q--) {
    int ty, u, v;
    scanf("%d%d%d", &ty, &u, &v);
    --u;
    if (ty == 1) {
      add(in[u], -a[u]);
      add(out[u], a[u]);
      a[u] = v > 0 ? v : -v;
      add(in[u], a[u]);
      add(out[u], -a[u]);
    } else {
      --v;
      int w = lca(u, v);
      long long ans = 0;
      if (w == u) {
        ans = (sum(in[v]) - sum(in[u])) * 2 - a[v] + a[u];
      } else if (w == v) {
        ans = (sum(in[u]) - sum(in[v])) * 2 - a[u] + a[v];
      } else {
        ans = 2 * (sum(in[v]) + sum(in[u])) - 4 * sum(in[w]) + 2 * a[w] - a[u] -
              a[v];
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
