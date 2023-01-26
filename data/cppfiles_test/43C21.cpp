#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool read(T &f) {
  char c;
  f = 0;
  while (c = getchar(), c > '9' || c < '0')
    ;
  while (f = (f << 1) + (f << 3) + c - '0', c = getchar(), c >= '0' && c <= '9')
    ;
  return true;
}
template <typename A, typename... B>
inline bool read(A &x, B &...y) {
  return read(x) && read(y...);
}
const int N = 2e5 + 5;
int n, m;
int father[N];
int maxx[N], E[N];
struct Edge {
  int to, next, dis;
} edge[N << 1];
int head[N], sum_edge;
int f[N][20], dis[N][20], dep[N];
struct Ques {
  int x, v, id;
} q[N];
struct EDGE {
  int x, y, dis;
} e[N];
int ans[N][2], dist[N];
inline bool cmp_e(EDGE a, EDGE b) { return a.dis > b.dis; }
inline bool cmp_q(Ques a, Ques b) { return a.v > b.v; }
inline int find(int x) {
  return father[x] == x ? x : father[x] = find(father[x]);
}
inline void Add_edge(int from, int to, int dis) {
  ++sum_edge;
  edge[sum_edge].to = to;
  edge[sum_edge].dis = dis;
  edge[sum_edge].next = head[from];
  head[from] = sum_edge;
}
inline void Pre_dfs(int u, int fa) {
  for (register int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa) continue;
    f[v][0] = u, dis[v][0] = edge[i].dis;
    dep[v] = dep[u] + 1;
    Pre_dfs(v, u);
  }
}
inline void Pre() {
  for (register int i = 1; i < 20; ++i)
    for (register int j = 1; j <= n; ++j)
      f[j][i] = f[f[j][i - 1]][i - 1],
      dis[j][i] = max(dis[j][i - 1], dis[f[j][i - 1]][i - 1]);
}
inline int Query(int a, int b) {
  if (dep[a] < dep[b]) a ^= b ^= a ^= b;
  int c = dep[a] - dep[b], ans = 0;
  for (register int i = 0; i < 20; ++i)
    if ((c >> i) & 1) ans = max(ans, dis[a][i]), a = f[a][i];
  if (a == b) return ans;
  for (register int i = 19; i >= 0; --i)
    if (f[a][i] != f[b][i])
      ans = max(ans, max(dis[a][i], dis[b][i])), a = f[a][i], b = f[b][i];
  return max(ans, max(dis[a][0], dis[b][0]));
}
int main() {
  read(n, m);
  for (register int i = 1; i <= n; ++i) read(E[i]);
  for (register int i = 1, a, b, c, t; i < n; ++i) {
    read(a, b, c, t);
    e[i].x = a, e[i].y = b, e[i].dis = c;
    Add_edge(a, b, t);
    Add_edge(b, a, t);
  }
  Pre_dfs(1, 0);
  Pre();
  sort(e + 1, e + n, cmp_e);
  for (register int i = 1; i <= n; ++i)
    father[i] = i, maxx[i] = E[i], dist[i] = 0;
  for (register int i = 1; i <= m; ++i) read(q[i].v, q[i].x), q[i].id = i;
  sort(q + 1, q + 1 + m, cmp_q);
  for (register int i = 1, id = 1; i <= m;) {
    if (e[id].dis >= q[i].v) {
      int x = e[id].x, y = e[id].y;
      int r1 = find(x), r2 = find(y);
      if (maxx[r1] == maxx[r2])
        dist[r1] = max(Query(r1, r2), max(dist[r1], dist[r2]));
      else if (maxx[r1] < maxx[r2])
        swap(r1, r2);
      father[r2] = r1;
      ++id;
    } else {
      int x = q[i].x, r = find(x);
      ans[q[i].id][0] = maxx[r];
      ans[q[i].id][1] = max(dist[r], Query(r, x));
      ++i;
    }
  }
  for (register int i = 1; i <= m; ++i) printf("%d %d\n", ans[i][0], ans[i][1]);
  return 0;
}
