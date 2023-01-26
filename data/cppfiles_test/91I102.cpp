#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const long long inf = 1e18;
struct Node {
  int u, v, w;
  bool operator<(const Node a) const {
    return w < a.w || w == a.w && u < a.u || w == a.w && u == a.u && v < a.v;
  }
};
set<Node> all;
multiset<int> s[maxn];
map<pair<int, int>, int> edge;
int t[maxn << 7], ls[maxn << 7], rs[maxn << 7], tot, X[maxn << 2], xtot,
    root[maxn], n, m;
int id(int x) { return lower_bound(X + 1, X + 1 + xtot, x) - X; }
void add(int &rt, int l, int r, int x, int v) {
  if (!rt) rt = ++tot;
  t[rt] += v;
  if (l == r) return;
  int mid = l + r >> 1;
  if (x <= mid) add(ls[rt], l, mid, x, v);
  if (x >= mid + 1) add(rs[rt], mid + 1, r, x, v);
}
int qry(int rt1, int rt2, int rt3, int l, int r, int limt) {
  if (l == r) {
    if (t[rt1] + t[rt2] != t[rt3]) return l;
    return 0;
  }
  int mid = l + r >> 1;
  if (t[ls[rt1]] + t[ls[rt2]] - (limt >= l && limt <= mid) == t[ls[rt3]])
    return qry(rs[rt1], rs[rt2], rs[rt3], mid + 1, r, limt);
  return qry(ls[rt1], ls[rt2], ls[rt3], l, mid, limt);
}
void add(int u, int v, int w) {
  edge[{v, u}] = edge[{u, v}] = w;
  s[u].insert(w);
  s[v].insert(w);
  all.insert(Node{u, v, w});
  w = id(w);
  add(root[u], 1, xtot, w, 1);
  add(root[v], 1, xtot, w, 1);
  add(root[0], 1, xtot, w, 1);
}
void del(int u, int v) {
  int w = edge[{u, v}];
  edge[{v, u}] = edge[{u, v}] = -1;
  s[u].erase(s[u].find(w));
  s[v].erase(s[v].find(w));
  all.erase(Node{u, v, w});
  all.erase(Node{v, u, w});
  w = id(w);
  add(root[u], 1, xtot, w, -1);
  add(root[v], 1, xtot, w, -1);
  add(root[0], 1, xtot, w, -1);
}
long long get2(multiset<int> &g, int x) {
  g.erase(g.find(x));
  if ((int)g.size() < 2) {
    g.insert(x);
    return inf;
  }
  long long ans = *g.begin();
  g.erase(g.begin());
  long long u = *g.begin();
  g.insert(ans);
  ans += u;
  g.insert(x);
  return ans;
}
long long work(int u, int v, int w) {
  long long ans = min(get2(s[u], w), get2(s[v], w)) + w;
  w = id(w);
  int l = 1, r = xtot, cur = qry(root[u], root[v], root[0], 1, xtot, w);
  if (cur) ans = min(ans, 1ll * X[w] + 1ll * X[cur]);
  return ans;
}
long long getans() {
  vector<Node> g;
  for (int i = 0; i < 4; ++i) {
    g.push_back(*all.begin());
    all.erase(all.begin());
  }
  long long ans = inf;
  for (auto u : g) {
    ans = min(ans, work(u.u, u.v, u.w));
    all.insert(u);
  }
  return ans;
}
struct Edge {
  int u, v, w;
} E[maxn];
struct QRY {
  int op, u, v, w;
} Q[maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
    X[++xtot] = E[i].w;
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int op, u, v;
    scanf("%d%d%d", &op, &u, &v);
    if (op) {
      int w;
      scanf("%d", &w);
      Q[i] = QRY{op, u, v, w};
      X[++xtot] = w;
    } else
      Q[i] = QRY{op, u, v, 0};
  }
  sort(X + 1, X + 1 + xtot);
  xtot = unique(X + 1, X + 1 + xtot) - (X + 1);
  for (int i = 0; i < m; ++i) {
    add(E[i].u, E[i].v, E[i].w);
  }
  printf("%lld\n", getans());
  for (int i = 0; i < q; ++i) {
    int op = Q[i].op, u = Q[i].u, v = Q[i].v, w = Q[i].w;
    if (!op) {
      del(u, v);
    } else
      add(u, v, w);
    printf("%lld\n", getans());
  }
}
