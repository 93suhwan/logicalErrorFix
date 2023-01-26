#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5, INF = 1e9;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
namespace maxflow {
int head[N], size = 1, cur[N], dep[N], S, T;
struct Edge {
  int v, nxt, flow;
} e[N << 2];
void link(int u, int v, int flow) {
  e[++size].v = v;
  e[size].nxt = head[u];
  e[size].flow = flow;
  head[u] = size;
}
void Elink(int u, int v, int flow) {
  link(u, v, flow);
  link(v, u, 0);
}
queue<int> q;
bool bfs() {
  for (int i = 0; i <= T; ++i) dep[i] = -1;
  q.push(S);
  dep[S] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = e[i].nxt) {
      if (e[i].flow > 0) {
        int v = e[i].v;
        if (dep[v] == -1) {
          dep[v] = dep[u] + 1;
          q.push(v);
        }
      }
    }
  }
  return dep[T] != -1;
}
int dfs(int u, int a) {
  if (u == T || a == 0) return a;
  int flow = 0, nw;
  for (int &i = cur[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (dep[v] == dep[u] + 1 && ((nw = dfs(v, min(a, e[i].flow))) > 0)) {
      flow += nw;
      e[i].flow -= nw;
      e[i ^ 1].flow += nw;
      a -= nw;
      if (!a) break;
    }
  }
  return flow;
}
void Dinic() {
  int res = 0;
  while (bfs()) {
    for (int i = 0; i <= T; ++i) cur[i] = head[i];
    res += dfs(S, INF);
  }
}
void clear() {
  size = 1;
  for (int i = 0; i <= T; ++i) head[i] = 0;
}
}  // namespace maxflow
vector<int> e[N];
int stk[N], t, w;
int n, m, b[N], len, q[N], ans[N], p[N], a[N];
int calc(int i, int x) { return abs(a[i] - x); }
void solve(int L, int R, int l, int r) {
  if (L > R) return;
  if (l == r) {
    for (int i = L; i <= R; ++i) ans[q[i]] = b[l];
    return;
  }
  int mid = (l + r) >> 1;
  maxflow::clear();
  maxflow::S = R - L + 2;
  maxflow::T = maxflow::S + 1;
  for (int i = L; i <= R; ++i) p[q[i]] = i - L + 1;
  for (int i = L; i <= R; ++i) {
    int nw = calc(q[i], b[mid]) - calc(q[i], b[mid + 1]), u = q[i];
    for (int v : e[u])
      if (p[v]) maxflow::Elink(p[u], p[v], INF);
    if (nw > 0)
      maxflow::Elink(maxflow::S, i - L + 1, nw);
    else
      maxflow::Elink(i - L + 1, maxflow::T, -nw);
  }
  for (int i = L; i <= R; ++i) p[q[i]] = 0;
  maxflow::Dinic();
  t = L;
  w = R;
  for (int i = L; i <= R; ++i)
    if (~maxflow::dep[i - L + 1])
      stk[w--] = q[i];
    else
      stk[t++] = q[i];
  for (int i = L; i <= R; ++i) q[i] = stk[i];
  solve(L, t - 1, l, mid);
  solve(w + 1, R, mid + 1, r);
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) b[i] = a[i] = read(), q[i] = i;
  sort(b + 1, b + n + 1);
  len = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    e[u].push_back(v);
  }
  solve(1, n, 1, len);
  for (int u = 1; u <= m; ++u)
    for (int v : e[u]) assert(ans[u] <= ans[v]);
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}
