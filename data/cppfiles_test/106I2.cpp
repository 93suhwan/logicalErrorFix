#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
struct CostFlow {
  static const int MXN = (1 << 20) + 2;
  static const long long INF = 102938475610293847LL;
  struct Edge {
    int v, r;
    long long f, c;
    Edge(int a, int b, int _c, int d) : v(a), r(b), f(_c), c(d) {}
  };
  int n, s, t, prv[MXN], prvL[MXN], inq[MXN];
  long long dis[MXN], fl, cost;
  vector<Edge> E[MXN];
  void init(int _n, int _s, int _t) {
    n = _n;
    s = _s;
    t = _t;
    for (int i = 0; i < n; i++) E[i].clear();
    fl = cost = 0;
  }
  void add_edge(int u, int v, long long f, long long c) {
    E[u].push_back(Edge(v, E[v].size(), f, c));
    E[v].push_back(Edge(u, E[u].size() - 1, 0, -c));
  }
  pair<long long, long long> flow(int k) {
    while (true) {
      for (int i = 0; i < n; i++) {
        dis[i] = INF;
        inq[i] = 0;
      }
      dis[s] = 0;
      queue<int> que;
      que.push(s);
      while (!que.empty()) {
        int u = que.front();
        que.pop();
        inq[u] = 0;
        for (int i = 0; i < E[u].size(); i++) {
          int v = E[u][i].v;
          long long w = E[u][i].c;
          if (E[u][i].f > 0 && dis[v] > dis[u] + w) {
            prv[v] = u;
            prvL[v] = i;
            dis[v] = dis[u] + w;
            if (!inq[v]) {
              inq[v] = 1;
              que.push(v);
            }
          }
        }
      }
      if (dis[t] == INF) break;
      long long tf = INF;
      for (int v = t, u, l; v != s; v = u) {
        u = prv[v];
        l = prvL[v];
        tf = min(tf, E[u][l].f);
      }
      for (int v = t, u, l; v != s; v = u) {
        u = prv[v];
        l = prvL[v];
        E[u][l].f -= tf;
        E[v][E[u][l].r].f += tf;
      }
      if (dis[t] > 0) break;
      cost += tf * dis[t];
      fl += tf;
      if (fl == k) break;
    }
    return {fl, cost};
  }
} flow;
int val[1 << 20];
int Index;
void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  int a[1 << 20];
  for (int i = 0; i < (1 << n); i++) scanf("%d", &a[i]);
  vector<pair<int, pair<int, int> > > v;
  for (int i = 0; i < (1 << n); i++) {
    if (__builtin_popcount(i) & 1) {
      for (int j = 0; j < n; j++) {
        v.push_back(
            make_pair(a[i] + a[i ^ (1 << j)], make_pair(i, i ^ (1 << j))));
      }
    }
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (int i = 0; i < n * k + 10 && i < v.size(); i++) {
    int a = v[i].second.first, b = v[i].second.second;
    if (!val[a]) {
      val[a] = ++Index;
    }
    if (!val[b]) {
      val[b] = ++Index;
    }
  }
  flow.init(Index + 2, 0, Index + 1);
  for (int i = 0; i < (1 << n); i++) {
    if (val[i]) {
      if (__builtin_popcount(i) & 1)
        flow.add_edge(0, val[i], 1, -a[i]);
      else
        flow.add_edge(val[i], Index + 1, 1, -a[i]);
    }
  }
  for (int i = 0; i < n * k + 10 && i < v.size(); i++) {
    flow.add_edge(val[v[i].second.first], val[v[i].second.second], 1, 0);
  }
  printf("%d\n", -flow.flow(k).second);
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
