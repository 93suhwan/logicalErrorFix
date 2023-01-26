#include <bits/stdc++.h>
using namespace std;
const long long N = 1015;
long long n, m, a[N], _a[N], ans[N];
vector<long long> e[N];
struct MaxFlow {
  struct edge {
    long long to, nxt, cap;
  } e[N << 2];
  long long n, S, T, tot = 1, head[N], cur[N];
  bool res[N];
  void clear() {
    for (; n > 0; n--) res[n] = head[n] = 0;
    tot = 1;
  }
  void add(long long u, long long v, long long cap) {
    e[++tot] = (edge){v, head[u], cap};
    head[u] = tot;
    e[++tot] = (edge){u, head[v], 0};
    head[v] = tot;
  }
  long long dep[N];
  queue<long long> q;
  bool bfs() {
    for (long long i = (1); i <= (n); i++) dep[i] = -1;
    dep[S] = 0;
    q.push(S);
    while (((long long)q.size())) {
      long long u = q.front();
      q.pop();
      cur[u] = head[u];
      for (long long i = head[u]; i; i = e[i].nxt) {
        long long v = e[i].to, cap = e[i].cap;
        if (cap > 0 && dep[v] == -1) {
          dep[v] = dep[u] + 1;
          q.push(v);
        }
      }
    }
    return dep[T] != -1;
  }
  long long dfs(long long u, long long dis) {
    if (u == T || dis == 0) return dis;
    long long flow = 0;
    for (long long i = cur[u]; i; i = e[i].nxt) {
      cur[u] = i;
      long long v = e[i].to, cap = e[i].cap;
      if (dep[v] == dep[u] + 1 && cap > 0) {
        long long f = dfs(v, min(cap, dis));
        if (f > 0) {
          dis -= f;
          flow += f;
          e[i].cap -= f;
          e[i ^ 1].cap += f;
          if (dis == 0) break;
        }
      }
    }
    return flow;
  }
  void dinic() {
    while (bfs()) dfs(S, 0x3f3f3f3f3f3f3f3f);
    function<void(long long)> find;
    find = [&](long long u) -> void {
      res[u] = 1;
      for (long long i = head[u]; i; i = e[i].nxt) {
        if (e[i].cap > 0 && !res[e[i].to]) find(e[i].to);
      }
    };
    find(S);
  }
} O;
long long id[N];
void solve(vector<long long> V, vector<pair<long long, long long> > E,
           long long l, long long r) {
  if (((long long)V.size()) == 0) return;
  if (l == r) {
    for (auto x : V) ans[x] = _a[l];
    return;
  }
  long long mid = (l + r) >> 1, vl = _a[mid], vr = _a[mid + 1];
  O.clear();
  O.n = ((long long)V.size()) + 2;
  O.S = ((long long)V.size()) + 1;
  O.T = ((long long)V.size()) + 2;
  for (long long i = (1); i <= (((long long)V.size())); i++) id[V[i - 1]] = i;
  for (auto [u, v] : E) O.add(id[u], id[v], 0x3f3f3f3f3f3f3f3f);
  for (long long i = (1); i <= (((long long)V.size())); i++) {
    long long v = -abs(a[V[i - 1]] - vr) + abs(a[V[i - 1]] - vl);
    if (v > 0)
      O.add(O.S, i, v);
    else
      O.add(i, O.T, -v);
  }
  O.dinic();
  vector<long long> nV[2];
  vector<pair<long long, long long> > nE[2];
  for (long long i = (1); i <= (((long long)V.size())); i++)
    nV[O.res[i]].push_back(V[i - 1]);
  for (auto [u, v] : E)
    if (O.res[id[u]] == O.res[id[v]]) nE[O.res[id[u]]].emplace_back(u, v);
  for (auto [u, v] : E) assert(O.res[id[u]] <= O.res[id[v]]);
  solve(nV[0], nE[0], l, mid);
  solve(nV[1], nE[1], mid + 1, r);
}
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = (1); i <= (n); i++) scanf("%lld", &a[i]), _a[i] = a[i];
  sort(_a + 1, _a + n + 1);
  long long _m = unique(_a + 1, _a + n + 1) - _a - 1;
  vector<pair<long long, long long> > E;
  vector<long long> V;
  for (long long i = (1); i <= (n); i++) V.emplace_back(i);
  for (long long i = (1); i <= (m); i++) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    E.emplace_back(u, v);
  }
  solve(V, E, 1, _m);
  for (auto [u, v] : E) assert(ans[u] <= ans[v]);
  for (long long i = (1); i <= (n); i++) printf("%lld ", ans[i]);
  return 0;
}
