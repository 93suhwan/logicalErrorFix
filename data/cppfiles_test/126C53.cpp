#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int N = 1010, M = 4;
namespace Flow {
struct Edge {
  int v;
  ll w;
  Edge *next, *rev;
} P[N * M * 4], *top, *g[N], *gp[N];
void init() {
  memset(P, 0, sizeof(P));
  memset(g, 0, sizeof(g));
  top = P;
}
Edge *add(int u, int v, ll w) {
  Edge *p = top++;
  p->v = v;
  p->w = w;
  p->next = g[u];
  g[u] = p;
  return p;
}
void link(int u, int v, ll w) {
  Edge *x = add(u, v, w), *y = add(v, u, 0);
  x->rev = y;
  y->rev = x;
}
queue<int> q;
int level[N];
void bfs(int s) {
  memset(level, -1, sizeof(level));
  q.push(s);
  level[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (Edge *p = g[u]; p; p = p->next)
      if (p->w && level[p->v] == -1) {
        q.push(p->v);
        level[p->v] = level[u] + 1;
      }
  }
}
ll dfs(int u, int t, ll lim = numeric_limits<ll>::max()) {
  if (u == t) return lim;
  ll flow = 0;
  for (Edge *&p = gp[u]; p; p = p->next) {
    if (p->w && level[p->v] == level[u] + 1) {
      ll f = dfs(p->v, t, min(lim - flow, p->w));
      p->w -= f;
      p->rev->w += f;
      flow += f;
      if (flow == lim) break;
    }
  }
  return flow;
}
ll dinic(int s, int t) {
  ll flow = 0;
  while (bfs(s), level[t] != -1) {
    memcpy(gp, g, sizeof(g));
    flow += dfs(s, t);
  }
  return flow;
}
}  // namespace Flow
ll val(ll x) { return x < 0 ? -x : x; }
ll b[N], ans[N];
int x[N], y[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> b[i];
  for (int i = 1; i <= m; ++i) cin >> x[i] >> y[i];
  ll mn = *min_element(b + 1, b + n + 1);
  for (int i = 1; i <= n; ++i) b[i] -= mn;
  for (int bit = 55; bit >= 0; --bit) {
    Flow::init();
    int s = 0, t = n + 1;
    for (int i = 1; i <= n; ++i) {
      Flow::link(s, i, val((ans[i] | (1LL << bit)) - 1 - b[i]));
      Flow::link(i, t, val((ans[i] | (1LL << bit)) - b[i]));
    }
    for (int i = 1; i <= m; ++i)
      if (ans[x[i]] == ans[y[i]])
        Flow::link(x[i], y[i], numeric_limits<ll>::max());
    Flow::dinic(s, t);
    for (int i = 1; i <= n; ++i)
      if (Flow::level[i] != -1) ans[i] |= 1 << bit;
  }
  for (int i = 1; i <= n; ++i) cout << (ans[i] + mn) << '\n';
  return 0;
}
