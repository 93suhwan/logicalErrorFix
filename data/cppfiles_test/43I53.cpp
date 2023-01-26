#include <bits/stdc++.h>
using namespace std;
const int N = (2e5 + 5) * 2;
int n, q, a[N];
struct Edge {
  int u, v, w1, w2;
} e[N];
typedef bool (*op)(const int &, const int &);
struct Kruskal {
  int f[N << 1];
  int getf(int x) { return f[x] == x ? x : f[x] = getf(f[x]); }
  int bz[N << 1][20], ch[N << 1][2], id[N], rt;
  void prepare(op cmp) {
    for (int i = (1); i < (n); ++i) id[i] = i;
    sort(id + 1, id + n, cmp);
    for (int i = (1); i < (n * 2); ++i) f[i] = i;
    for (int i = (1); i <= (n - 1); ++i) {
      int u = getf(e[id[i]].u), v = getf(e[id[i]].v);
      f[u] = f[v] = n + id[i];
      ch[n + id[i]][0] = u;
      ch[n + id[i]][1] = v;
      bz[u][0] = bz[v][0] = n + id[i];
    }
    for (int i = (2 * n - 1); i >= (1); --i) {
      if (i > n)
        for (int j = (1); j <= (18); ++j)
          bz[id[i]][j] = bz[bz[id[i]][j - 1]][j - 1];
      else
        for (int j = (1); j <= (18); ++j) bz[i][j] = bz[bz[i][j - 1]][j - 1];
    }
    rt = id[n - 1];
  }
} T1, T2;
int dp[N][3], L[N], R[N], dfc;
void dfs1(int u) {
  if (T2.ch[u][0]) {
    int lc = T2.ch[u][0], rc = T2.ch[u][1];
    dfs1(lc), dfs1(rc);
    L[u] = L[lc], R[u] = R[rc];
  } else
    L[u] = R[u] = ++dfc;
}
void dfs2(int u) {
  if (T1.ch[u][0]) {
    int lc = T1.ch[u][0], rc = T1.ch[u][1];
    dfs2(lc), dfs2(rc);
    if (dp[lc][2] == dp[rc][2]) {
      dp[u][0] = min(dp[lc][0], dp[rc][0]);
      dp[u][1] = max(dp[lc][1], dp[rc][1]);
    } else if (dp[lc][2] > dp[rc][2]) {
      dp[u][0] = dp[lc][0];
      dp[u][1] = dp[lc][1];
    } else {
      dp[u][0] = dp[rc][0];
      dp[u][1] = dp[rc][1];
    }
    dp[u][2] = max(dp[lc][2], dp[rc][2]);
  } else {
    dp[u][0] = dp[u][1] = L[u];
    dp[u][2] = a[u];
  }
}
int getval(int x, int v) {
  if (L[x] == v) return 0;
  for (int i = (18); i >= (0); --i) {
    int y = T2.bz[x][i];
    if (y && (L[y] > v || v > R[y])) x = y;
  }
  return e[T2.bz[x][0] - n].w2;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = (1); i <= (n); ++i) scanf("%d", a + i);
  for (int i = 1; i < n; ++i)
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].w1, &e[i].w2);
  T1.prepare([](const int &i, const int &j) { return e[i].w1 > e[j].w1; });
  T2.prepare([](const int &i, const int &j) { return e[i].w2 < e[j].w2; });
  dfs1(T2.rt + n);
  dfs2(T1.rt + n);
  while (q--) {
    static int V, x;
    scanf("%d%d", &V, &x);
    int u = x, v;
    for (int i = (18); i >= (0); --i) {
      v = T1.bz[u][i];
      if (v && e[v - n].w1 >= V) u = v;
    }
    printf("%d %d\n", dp[u][2], max(getval(x, dp[u][0]), getval(x, dp[u][1])));
  }
  return 0;
}
