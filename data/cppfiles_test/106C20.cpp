#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000;
const int INF = 1e9;
int n, k;
struct edge {
  int from, to, cap, flow, cost;
};
int tot, s, t;
vector<edge> edges;
vector<int> G[maxn];
int inq[maxn];
int d[maxn];
int p[maxn];
int a[maxn];
void init() {
  for (int i = 0; i <= t; i++) G[i].clear();
  edges.clear();
}
void addedge(int from, int to, int cap, int cost) {
  edges.push_back(edge{from, to, cap, 0, cost});
  edges.push_back(edge{to, from, 0, 0, -cost});
  tot = edges.size();
  G[from].push_back(tot - 2);
  G[to].push_back(tot - 1);
}
bool spfa(int &flow, int &cost) {
  for (int i = 0; i <= t; i++) d[i] = INF;
  memset(inq, 0, sizeof(inq));
  d[s] = 0;
  inq[s] = 1;
  p[s] = 0;
  a[s] = INF;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = 0;
    for (int i = 0; i < G[u].size(); i++) {
      edge &e = edges[G[u][i]];
      if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
        d[e.to] = d[u] + e.cost;
        p[e.to] = G[u][i];
        a[e.to] = min(a[u], e.cap - e.flow);
        if (!inq[e.to]) {
          q.push(e.to);
          inq[e.to] = 1;
        }
      }
    }
  }
  if (d[t] == INF) return false;
  flow += a[t];
  cost += d[t] * a[t];
  int u = t;
  while (u != s) {
    edges[p[u]].flow += a[t];
    edges[p[u] ^ 1].flow -= a[t];
    u = edges[p[u]].from;
  }
  return true;
}
int mincost() {
  int flow = 0, cost = 0;
  while (spfa(flow, cost))
    ;
  return cost;
}
int value[1 << 21];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  set<tuple<int, int, int> > ss;
  cin >> n >> k;
  for (int i = 0; i < (1 << n); i += 1) {
    cin >> value[i];
  }
  int lim = 2 * n * k;
  for (int i = 0; i < (1 << n); i += 1) {
    if (__builtin_popcount(i) & 1) continue;
    for (int j = 0; j < n; j += 1) {
      ss.emplace(value[i] + value[i ^ (1 << j)], i, i ^ (1 << j));
      if (ss.size() > lim) ss.erase(ss.begin());
    }
  }
  vector<int> X, Y;
  X.emplace_back(-1);
  Y.emplace_back(-1);
  for (auto [x, y, z] : ss) {
    X.emplace_back(y);
    Y.emplace_back(z);
  }
  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());
  sort(Y.begin(), Y.end());
  Y.erase(unique(Y.begin(), Y.end()), Y.end());
  for (auto [x, y, z] : ss) {
    int pl = lower_bound(X.begin(), X.end(), y) - X.begin();
    int pr = lower_bound(Y.begin(), Y.end(), z) - Y.begin();
    addedge(pl, pr + X.size(), 1, 0);
  }
  s = 0;
  int tt = X.size() + Y.size() + 1;
  for (int i = 1; i < X.size(); i += 1) {
    addedge(s, i, 1, -value[X[i]]);
  }
  for (int i = 1; i < Y.size(); i += 1) {
    addedge(i + X.size(), tt, 1, -value[Y[i]]);
  }
  t = tt + 1;
  addedge(tt, t, k, 0);
  cout << -mincost() << endl;
  return 0;
}
