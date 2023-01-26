#include <bits/stdc++.h>
using namespace std;
const unsigned long long INF = 1ll << 62;
const int N = 3e3 + 5, M = 64;
unsigned long long ans, c[N];
vector<int> e[N];
int n, m, flag, tmp[N];
int a[N], w[N], f[N], id[N];
inline void add_edge(int x, int y) { e[x].push_back(y); }
inline void input() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", w + i), a[i] = i;
  for (int x, y; m--; add_edge(x, y)) scanf("%d%d", &y, &x);
}
inline void init() {}
namespace MF {
queue<int> q;
int S, T, tot, h[N], cur[N], dis[N], pre[N];
struct edge {
  int t, n;
  unsigned long long w;
} e[N * M << 1];
inline void add_edge(int x, int y, unsigned long long w) {
  e[++tot] = (edge){y, h[x], w}, h[x] = tot;
  e[++tot] = (edge){x, h[y], 0}, h[y] = tot;
}
inline void init(int x) {
  S = x + 1, T = x + 2, tot = 1, memset(h, 0, T + 1 << 2);
}
inline int bfs() {
  memcpy(cur, h, T + 1 << 2), memset(dis, 0, T + 1 << 2), q.push(S), dis[S] = 1;
  for (int u; !q.empty(); q.pop())
    for (int &i = cur[u = q.front()], v; v = e[i].t, i; i = e[i].n)
      if (e[i].w && !dis[v]) q.push(v), dis[v] = dis[u] + 1, pre[v] = u;
  return dis[T];
}
inline int dfs(int u, unsigned long long res) {
  if (!res || u == T) return res;
  int out = 0, f;
  for (int &i = cur[u], v; v = e[i].t, i; i = e[i].n)
    if (dis[v] == dis[u] + 1 && (f = dfs(v, min(e[i].w, res)))) {
      e[i].w -= f, e[i ^ 1].w += f, res -= f, out += f;
      if (!res) return out;
    }
  return out;
}
inline void dinic() {
  while (bfs()) memcpy(cur, h, T + 1 << 2), dfs(S, INF);
}
}  // namespace MF
unsigned long long pw(int x) { return x < 0 ? -x : x; }
inline void solve(int l, int r, int L, int R) {
  if (l > r || L >= R) return;
  unsigned long long w1, w2;
  int mid = L + R >> 1, op = l - 1, ed = r + 1;
  MF::init(r - l + 1);
  for (int i = l; i <= r; i++) id[a[i]] = i - l + 1;
  for (int i = l; i <= r; i++)
    if ((w1 = pw(w[a[i]] - mid)) > (w2 = pw(w[a[i]] - mid - 1)))
      MF::add_edge(i - l + 1, MF::T, w1 - w2);
    else
      MF::add_edge(MF::S, i - l + 1, w2 - w1);
  for (int u = l; u <= r; u++)
    for (int v : e[a[u]])
      if (id[v]) MF::add_edge(u - l + 1, id[v], INF);
  MF::dinic();
  for (int i = l; i <= r; i++) f[a[i]] = mid + !!MF::cur[i - l + 1];
  for (int i = l; i <= r; i++) (f[a[i]] == mid ? tmp[++op] : tmp[--ed]) = a[i];
  for (int i = l; i <= r; i++) id[a[i] = tmp[i]] = 0;
  solve(l, op, L, mid), solve(ed, r, mid + 1, R);
}
inline void work() {
  int L = 1e9, R = 0;
  for (int i = 1; i <= n; i++) L = min(L, w[i]), R = max(R, w[i]);
  solve(1, n, L, R);
  for (int i = 1; i <= n; i++) ans += pw(w[i] - f[i]);
  for (int i = 1; i <= n; i++) cout << f[i] << " ";
}
int main() {
  input();
  init();
  work();
  return 0;
}
