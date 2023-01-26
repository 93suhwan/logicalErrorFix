#include <bits/stdc++.h>
using namespace std;
const int N = 1015;
int n, m, a[N], _a[N], ans[N];
vector<int> e[N];
struct MaxFlow {
  struct edge {
    int to, nxt, cap;
  } e[N << 2];
  int n, S, T, tot = 1, head[N], cur[N];
  bool res[N];
  void clear() {
    for (; n > 0; n--) res[n] = head[n] = 0;
    tot = 1;
  }
  void add(int u, int v, int cap) {
    e[++tot] = (edge){v, head[u], cap};
    head[u] = tot;
    e[++tot] = (edge){u, head[v], 0};
    head[v] = tot;
  }
  int dep[N];
  queue<int> q;
  bool bfs() {
    for (int i = (1); i <= (n); i++) dep[i] = -1;
    dep[S] = 0;
    q.push(S);
    while (((int)q.size())) {
      int u = q.front();
      q.pop();
      cur[u] = head[u];
      for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to, cap = e[i].cap;
        if (cap > 0 && dep[v] == -1) {
          dep[v] = dep[u] + 1;
          q.push(v);
        }
      }
    }
    return dep[T] != -1;
  }
  int dfs(int u, int dis) {
    if (u == T || dis == 0) return dis;
    int flow = 0;
    for (int i = cur[u]; i; i = e[i].nxt) {
      cur[u] = i;
      int v = e[i].to, cap = e[i].cap;
      if (dep[v] == dep[u] + 1 && cap > 0) {
        int f = dfs(v, min(cap, dis));
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
    while (bfs()) dfs(S, 0x3f3f3f3f);
    function<void(int)> find;
    find = [&](int u) -> void {
      res[u] = 1;
      for (int i = head[u]; i; i = e[i].nxt) {
        if (e[i].cap > 0 && !res[e[i].to]) find(e[i].to);
      }
    };
    find(S);
  }
} O;
int id[N];
void solve(vector<int> V, vector<pair<int, int> > E, int l, int r) {
  if (((int)V.size()) == 0) return;
  if (l == r) {
    for (auto x : V) ans[x] = _a[l];
    return;
  }
  int mid = (l + r) >> 1, vl = _a[mid], vr = _a[mid + 1];
  O.clear();
  O.n = ((int)V.size()) + 2;
  O.S = ((int)V.size()) + 1;
  O.T = ((int)V.size()) + 2;
  for (int i = (1); i <= (((int)V.size())); i++) id[V[i - 1]] = i;
  for (auto [u, v] : E) O.add(id[u], id[v], 0x3f3f3f3f);
  for (int i = (1); i <= (((int)V.size())); i++) {
    int v = -abs(a[V[i - 1]] - vr) + abs(a[V[i - 1]] - vl);
    if (v > 0)
      O.add(O.S, i, v);
    else
      O.add(i, O.T, -v);
  }
  O.dinic();
  vector<int> nV[2];
  vector<pair<int, int> > nE[2];
  for (int i = (1); i <= (((int)V.size())); i++)
    nV[O.res[i]].push_back(V[i - 1]);
  for (auto [u, v] : E)
    if (O.res[id[u]] == O.res[id[v]]) nE[O.res[id[u]]].emplace_back(u, v);
  solve(nV[0], nE[0], l, mid);
  solve(nV[1], nE[1], mid + 1, r);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]), _a[i] = a[i];
  sort(_a + 1, _a + n + 1);
  int _m = unique(_a + 1, _a + n + 1) - _a - 1;
  vector<pair<int, int> > E;
  vector<int> V;
  for (int i = (1); i <= (n); i++) V.emplace_back(i);
  for (int i = (1); i <= (m); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    E.emplace_back(u, v);
  }
  solve(V, E, 1, _m);
  for (int i = (1); i <= (n); i++) printf("%d ", ans[i]);
  return 0;
}
