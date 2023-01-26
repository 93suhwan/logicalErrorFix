#include <bits/stdc++.h>
namespace MF {
int n, s, t;
int hd[10005], _hd;
struct edge {
  int v, f, nxt;
} e[10005];
inline void addedge(int u, int v, int f) {
  e[++_hd] = (edge){v, f, hd[u]};
  hd[u] = _hd;
  e[++_hd] = (edge){u, 0, hd[v]};
  hd[v] = _hd;
}
inline void init(int n_, int s_, int t_) {
  for (int i = 1; i <= n; i++) hd[i] = 0;
  _hd = 1;
  n = n_, s = s_, t = t_;
}
std::queue<int> q;
int cur[10005], dis[10005];
inline bool bfs() {
  for (int i = 1; i <= n; i++) cur[i] = hd[i];
  for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f;
  dis[s] = 0;
  q.push(s);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = hd[u]; i; i = e[i].nxt) {
      int v = e[i].v, f = e[i].f;
      if (f && dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
  return dis[t] < 0x3f3f3f3f;
}
inline int dfs(int u, int lmt) {
  if (u == t || !lmt) return lmt;
  int res = 0;
  for (int i = cur[u]; i; i = e[i].nxt) {
    cur[u] = i;
    int v = e[i].v, f = e[i].f;
    if (dis[v] != dis[u] + 1) continue;
    f = dfs(v, std::min(lmt, f));
    e[i].f -= f;
    e[i ^ 1].f += f;
    lmt -= f;
    res += f;
    if (!lmt) break;
  }
  return res;
}
inline void sol() {
  while (bfs()) dfs(s, 0x3f3f3f3f);
}
}  // namespace MF
int n, m, y[10005];
std::vector<int> e[10005];
inline int cal(int u, int k) { return k > y[u] ? k - y[u] : y[u] - k; }
int tot, Y[10005], f[10005], p[10005], id[10005], q[10005];
inline void sol(int L, int R, int l, int r) {
  if (l > r) return;
  if (L == R) {
    for (int i = l; i <= r; i++) f[p[i]] = Y[L];
    return;
  }
  int mid = (L + R) >> 1;
  MF::init(r - l + 3, r - l + 2, r - l + 3);
  for (int i = l; i <= r; i++) id[p[i]] = i - l + 1;
  for (int i = l; i <= r; i++) {
    int u = p[i], w = cal(u, Y[mid]) - cal(u, Y[mid + 1]);
    if (w > 0)
      MF::addedge(MF::s, id[u], w);
    else
      MF::addedge(id[u], MF::t, -w);
    for (auto v : e[u])
      if (id[v]) MF::addedge(id[u], id[v], 0x3f3f3f3f);
  }
  MF::sol();
  int pm = l - 1;
  for (int i = l; i <= r; i++)
    if (MF::dis[id[p[i]]] == 0x3f3f3f3f) q[++pm] = p[i];
  int tmp = pm;
  for (int i = l; i <= r; i++)
    if (MF::dis[id[p[i]]] < 0x3f3f3f3f) q[++tmp] = p[i];
  for (int i = l; i <= r; i++) p[i] = q[i];
  for (int i = l; i <= r; i++) id[p[i]] = 0;
  sol(L, mid, l, pm);
  sol(mid + 1, R, pm + 1, r);
}
int ans;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &y[i]), Y[++tot] = y[i];
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
  }
  std::sort(Y + 1, Y + tot + 1);
  tot = std::unique(Y + 1, Y + tot + 1) - Y - 1;
  for (int i = 1; i <= n; i++) p[i] = i;
  sol(1, tot, 1, n);
  for (int i = 1; i <= n; i++) printf("%d ", f[i]);
  puts("");
}
