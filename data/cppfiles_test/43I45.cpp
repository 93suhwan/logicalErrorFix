#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g[1000010];
int n, m;
int f[1000010], fa[1000010][20], maxx[1000010][20], deep[1000010],
    maxval[1000010], maxpos[1000010], maxf[1000010], ans1[1000010],
    ans2[1000010];
struct Edge {
  int u, v, c, f;
  bool operator<(const Edge& res) const { return c > res.c; }
} e[1000010];
struct Query {
  int v, u, id;
  bool operator<(const Query& res) const { return v > res.v; }
} q[1000010];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void dfs(int u, int ff) {
  deep[u] = deep[ff] + 1;
  for (register int i = 1; i <= 18; i++) {
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
    maxx[u][i] = max(maxx[u][i - 1], maxx[fa[u][i - 1]][i - 1]);
  }
  for (auto i : g[u]) {
    if (i.first == ff) continue;
    fa[i.first][0] = u;
    maxx[i.first][0] = i.second;
    dfs(i.first, u);
  }
}
int getmax(int x, int y) {
  int res = 0;
  if (deep[y] > deep[x]) swap(x, y);
  for (register int i = 18; ~i; i--) {
    if (deep[fa[x][i]] >= deep[y]) {
      res = max(res, maxx[x][i]);
      x = fa[x][i];
    }
  }
  if (x == y) return res;
  for (register int i = 18; ~i; i--) {
    if (fa[x][i] != fa[y][i]) {
      res = max(res, max(maxx[x][i], maxx[y][i]));
      x = fa[x][i];
      y = fa[y][i];
    }
  }
  return max(res, max(maxx[x][0], maxx[y][0]));
}
int main() {
  scanf("%d%d", &n, &m);
  for (register int i = 1; i <= n; i++) scanf("%d", &maxval[i]);
  for (register int i = 1; i < n; i++) {
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].c, &e[i].f);
    g[e[i].u].push_back(make_pair(e[i].v, e[i].f));
    g[e[i].v].push_back(make_pair(e[i].u, e[i].f));
  }
  for (register int i = 1; i <= m; i++) {
    scanf("%d%d", &q[i].v, &q[i].u);
    q[i].id = i;
  }
  dfs(1, 0);
  sort(e + 1, e + n);
  sort(q + 1, q + m + 1);
  for (register int i = 1; i <= n; i++) f[i] = maxpos[i] = i;
  for (register int i = 1, j = 1; i < n || j <= m;) {
    for (; j <= m && q[j].v > e[i].c; j++) {
      int now = find(q[j].u);
      ans1[q[j].id] = maxval[now];
      ans2[q[j].id] = max(maxf[now], getmax(q[j].u, maxpos[now]));
    }
    int nowc = e[i].c;
    for (; i < n && e[i].c == nowc; i++) {
      int u = find(e[i].u), v = find(e[i].v);
      f[u] = v;
      if (maxval[u] > maxval[v]) {
        maxpos[v] = maxpos[u];
        maxval[v] = maxval[u];
        maxf[v] = maxf[u];
      } else if (maxval[u] == maxval[v]) {
        maxf[v] = max(e[i].f, max(maxf[u], maxf[v]));
      }
    }
  }
  for (register int i = 1; i <= m; i++) printf("%d %d\n", ans1[i], ans2[i]);
  return 0;
}
