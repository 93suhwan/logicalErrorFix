#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, q, a[N], h[N], cnt, fa[20][N], val[20][N], dep[N];
struct edge {
  int v, w, n;
} e[N << 1];
struct D {
  int u, v, c;
} dat[N];
struct qry {
  int id, x, c;
} Q[N];
pair<int, int> ans[N];
int get(int x, int y) {
  int ret = 0;
  if (dep[x] < dep[y]) swap(x, y);
  int d = dep[x] - dep[y];
  for (int i = 0; i <= 17; ++i)
    if (d & (1 << i)) ret = max(ret, val[i][x]), x = fa[i][x];
  for (int i = 17; i >= 0; --i)
    if (fa[i][x] != fa[i][y])
      ret = max(ret, max(val[i][x], val[i][y])), x = fa[i][x], y = fa[i][y];
  if (x != y) ret = max(ret, max(val[0][x], val[0][y]));
  return ret;
}
struct ds {
  int f, mx, l;
  int query(int x) { return max(mx, get(x, l)); }
} t[N];
int getfa(int x) { return t[x].f == x ? x : t[x].f = getfa(t[x].f); }
void merge(int x, int y) {
  x = getfa(x), y = getfa(y), t[x].f = y;
  if (a[t[x].l] == a[t[y].l])
    t[y].mx = max(t[y].mx, get(t[x].l, t[y].l));
  else if (a[t[x].l] > a[t[y].l])
    t[y].mx = t[x].mx, t[y].l = t[x].l;
}
int getint() {
  char ch;
  while (!isdigit(ch = getchar()))
    ;
  int x = ch - 48;
  while (isdigit(ch = getchar())) x = x * 10 + ch - 48;
  return x;
}
void addedge(int u, int v, int w) {
  e[cnt] = (edge){v, w, h[u]}, h[u] = cnt++;
  e[cnt] = (edge){u, w, h[v]}, h[v] = cnt++;
}
void dfs(int x, int f) {
  fa[0][x] = f, dep[x] = dep[f] + 1;
  for (int i = h[x]; i != -1; i = e[i].n)
    if (e[i].v != f) val[0][e[i].v] = e[i].w, dfs(e[i].v, x);
}
bool cmp1(D a, D b) { return a.c > b.c; }
bool cmp2(qry a, qry b) { return a.c > b.c; }
void solve() {
  sort(dat + 1, dat + n, cmp1);
  for (int i = 1; i <= q; ++i) {
    int v = getint(), x = getint();
    Q[i] = (qry){i, x, v};
  }
  for (int i = 1; i <= n; ++i) t[i].f = t[i].l = i;
  sort(Q + 1, Q + 1 + q, cmp2);
  int p = 1;
  for (int i = 1; i <= q; ++i) {
    while (p <= n - 1 && dat[p].c >= Q[i].c) merge(dat[p].u, dat[p].v), ++p;
    int x = Q[i].x, y = getfa(x);
    ans[Q[i].id] = make_pair(a[t[y].l], t[y].query(x));
  }
  for (int i = 1; i <= q; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
}
int main() {
  n = getint(), q = getint();
  for (int i = 1; i <= n; ++i) a[i] = getint();
  memset(h, -1, sizeof(h));
  for (int i = 1; i <= n - 1; ++i) {
    dat[i].u = getint(), dat[i].v = getint(), dat[i].c = getint();
    addedge(dat[i].u, dat[i].v, getint());
  }
  dfs(1, 0);
  for (int i = 1; i <= 17; ++i)
    for (int j = 1; j <= n; ++j)
      fa[i][j] = fa[i - 1][fa[i - 1][j]],
      val[i][j] = max(val[i - 1][j], val[i - 1][fa[i - 1][j]]);
  solve();
  return 0;
}
