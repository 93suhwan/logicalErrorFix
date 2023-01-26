#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct E {
  int a, b, c, t;
} e[maxn];
struct query {
  int v, x, p;
} q[maxn];
int head[maxn], nxt[maxn << 1], to[maxn << 1], w[maxn << 1], cnt;
int v[maxn], fa[maxn], maxv[maxn], maxp[maxn], val[maxn], dep[maxn];
int pre[maxn][20], maxlv[maxn][20];
int ansp[maxn], ans[maxn];
void add(int x, int y, int t) {
  nxt[++cnt] = head[x];
  head[x] = cnt;
  to[cnt] = y;
  w[cnt] = t;
}
bool cmp(E x, E y) { return x.c > y.c; }
bool cmp2(query xx, query yy) { return xx.v > yy.v; }
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void dfs(int x, int f, int lv) {
  pre[x][0] = f;
  maxlv[x][0] = lv;
  for (int i = 0; i < 18; i++)
    if (pre[x][i] != 0) {
      pre[x][i + 1] = pre[pre[x][i]][i];
      maxlv[x][i + 1] = max(maxlv[x][i], maxlv[pre[x][i]][i]);
    } else
      maxlv[x][i + 1] = maxlv[x][i];
  int y;
  for (int i = head[x]; i; i = nxt[i]) {
    y = to[i];
    if (y == f) continue;
    dep[y] = dep[x] + 1;
    dfs(y, x, w[i]);
  }
}
int cal(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int res = 0;
  for (int i = 18; i >= 0; i--)
    if (dep[pre[x][i]] >= dep[y]) res = max(res, maxlv[x][i]), x = pre[x][i];
  if (x == y) return res;
  for (int i = 18; i >= 0; i--)
    if (pre[x][i] != pre[y][i]) {
      res = max(res, maxlv[x][i]);
      res = max(res, maxlv[y][i]);
      x = pre[x][i];
      y = pre[y][i];
    }
  res = max(res, maxlv[x][0]);
  res = max(res, maxlv[y][0]);
  return res;
}
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (maxv[fx] != maxv[fy]) {
    if (maxv[fx] > maxv[fy])
      fa[fy] = fx;
    else
      fa[fx] = fy;
  } else {
    fa[fx] = fy;
    val[fy] = max(val[fy], val[fx]);
    val[fy] = max(val[fy], cal(maxp[fy], maxp[fx]));
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i < n; i++) {
    scanf("%d%d%d%d", &e[i].a, &e[i].b, &e[i].c, &e[i].t);
    add(e[i].a, e[i].b, e[i].t);
    add(e[i].b, e[i].a, e[i].t);
  }
  for (int i = 1; i <= n; i++)
    fa[i] = i, maxv[i] = v[i], maxp[i] = i, val[i] = 0;
  dfs(1, 0, 0);
  sort(e + 1, e + n, cmp);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &q[i].v, &q[i].x);
    q[i].p = i;
  }
  sort(q + 1, q + 1 + m, cmp2);
  int now = 1;
  for (int i = 1; i <= m; i++) {
    while (now < n && e[now].c >= q[i].v) merge(e[now].a, e[now].b), now++;
    int tmp = find(q[i].x);
    ansp[q[i].p] = maxv[tmp];
    ans[q[i].p] = max(val[tmp], cal(maxp[tmp], q[i].x));
  }
  for (int i = 1; i <= m; i++) printf("%d %d\n", ansp[i], ans[i]);
  return 0;
}
