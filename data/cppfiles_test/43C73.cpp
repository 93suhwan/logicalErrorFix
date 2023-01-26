#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const int M = 5e5 + 5;
int n, m, sign;
int siz[M], prt[M], top[M], val[M], dfn[M];
int fp[M], d[M], dis[M], son[M], fa[M], vis[M];
struct Edge {
  int x, y, d;
} e[M];
struct Tre {
  int l, r, Mx, cov;
} tre[M << 2];
std ::vector<int> P[M], D[M];
inline void dfs(int x, int fa, int dep) {
  d[x] = dep, siz[x] = 1;
  for (int i = 0; i < P[x].size(); ++i) {
    int y = P[x][i];
    if (y == fa) continue;
    prt[y] = x, dis[y] = dis[x] ^ D[x][i];
    dfs(y, x, dep + 1);
    siz[x] += siz[y];
    if (son[x] == -1 || siz[y] > siz[son[x]]) son[x] = y;
  }
}
inline void dfs(int x, int sp) {
  top[x] = sp, fp[dfn[x] = ++sign] = x;
  if (son[x] != -1) dfs(son[x], sp);
  for (int i = 0; i < P[x].size(); ++i)
    if (P[x][i] != prt[x] && P[x][i] != son[x]) dfs(P[x][i], P[x][i]);
}
inline void push_up(int p) {
  tre[p].Mx = std ::max(tre[p << 1].Mx, tre[p << 1 | 1].Mx);
}
inline void push_down_cov(int p) { tre[p].cov = 1, tre[p].Mx = 1; }
inline void push_down(int p) {
  if (!tre[p].cov) return;
  push_down_cov(p << 1), push_down_cov(p << 1 | 1);
  tre[p].cov = 0;
}
inline void build(int p, int l, int r) {
  tre[p].l = l, tre[p].r = r;
  if (l == r) return;
  int mid = l + r >> 1;
  build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
}
inline void update(int p, int l, int r) {
  if (l <= tre[p].l && tre[p].r <= r) {
    push_down_cov(p);
    return;
  }
  int mid = tre[p].l + tre[p].r >> 1;
  push_down(p);
  if (l <= mid) update(p << 1, l, r);
  if (r > mid) update(p << 1 | 1, l, r);
  push_up(p);
}
inline int Query(int p, int l, int r) {
  if (l <= tre[p].l && tre[p].r <= r) return tre[p].Mx;
  int mid = tre[p].l + tre[p].r >> 1, res = 0;
  push_down(p);
  if (l <= mid) res = std ::max(res, Query(p << 1, l, r));
  if (r > mid) res = std ::max(res, Query(p << 1 | 1, l, r));
  return res;
}
inline void update_path(int x, int y) {
  while (top[x] ^ top[y]) {
    if (d[top[x]] < d[top[y]]) std ::swap(x, y);
    update(1, dfn[top[x]], dfn[x]);
    x = prt[top[x]];
  }
  if (x == y) return;
  if (dfn[x] > dfn[y]) std ::swap(x, y);
  update(1, dfn[x] + 1, dfn[y]);
}
inline int Query_path(int x, int y) {
  int res = 0;
  while (top[x] ^ top[y]) {
    if (d[top[x]] < d[top[y]]) std ::swap(x, y);
    res = std ::max(res, Query(1, dfn[top[x]], dfn[x]));
    x = prt[top[x]];
  }
  if (x == y) return res;
  if (dfn[x] > dfn[y]) std ::swap(x, y);
  return std ::max(res, Query(1, dfn[x] + 1, dfn[y]));
}
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline int read() {
  int f = 1, s = 0;
  char ch = getchar();
  while (!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();
  while (isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return f * s;
}
int main() {
  memset(son, -1, sizeof(son));
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= m; ++i) {
    e[i].x = read(), e[i].y = read(), e[i].d = read();
    int kx = find(e[i].x), ky = find(e[i].y);
    if (kx == ky) continue;
    vis[i] = 1, fa[kx] = ky;
    int x = e[i].x, y = e[i].y;
    P[x].push_back(y), P[y].push_back(x);
    D[x].push_back(e[i].d), D[y].push_back(e[i].d);
  }
  for (int i = 1; i <= n; ++i)
    if (!siz[i]) dfs(i, 0, i), dfs(i, i);
  build(1, 1, n);
  for (int i = 1; i <= m; ++i) {
    if (vis[i]) {
      puts("YES");
      continue;
    }
    int x = e[i].x, y = e[i].y, d = e[i].d;
    int val = (dis[x] ^ dis[y] ^ d);
    if (!val) {
      puts("NO");
      continue;
    }
    if (Query_path(x, y) == 0)
      puts("YES"), update_path(x, y);
    else
      puts("NO");
  }
  return 0;
}
