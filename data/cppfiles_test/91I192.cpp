#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m;
struct edge {
  int u, v, w;
  edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
  bool operator<(const edge& a) const {
    if (w != a.w) return w < a.w;
    if (u != a.u) return u < a.u;
    return v < a.v;
  }
};
map<pair<int, int>, int> dis;
set<edge> g[maxn];
const long long inf = 0x3f3f3f3f;
map<edge, int> cnt;
set<edge> cur;
void add(int u) {
  int t = 0;
  for (auto x : g[u]) {
    if (++t > 3) break;
    if (++cnt[x] == 2) cur.insert(x);
  }
}
void del(int u) {
  int t = 0;
  for (auto x : g[u]) {
    if (++t > 3) break;
    if (--cnt[x] == 1) assert(cur.count(x)), cur.erase(x);
  }
}
void add(int u, int v, int w) {
  if (u > v) swap(u, v);
  del(u);
  del(v);
  g[u].insert(edge(u, v, w)), g[v].insert(edge(u, v, w));
  dis[pair<int, int>(u, v)] = w;
  add(u);
  add(v);
}
void del(int u, int v) {
  if (u > v) swap(u, v);
  assert(dis.count(pair<int, int>(u, v)));
  int w = dis[pair<int, int>(u, v)];
  del(u);
  del(v);
  g[u].erase(edge(u, v, w)), g[v].erase(edge(u, v, w));
  add(u);
  add(v);
}
bool check(edge x, edge y, edge z) {
  set<int> s;
  s.insert(x.u), s.insert(x.v);
  s.insert(y.u), s.insert(y.v);
  s.insert(z.u), s.insert(z.v);
  return s.size() == 3;
}
long long qry() {
  long long ans = 0x3f3f3f3f3f3f3f3f;
  vector<edge> t;
  int p = 0;
  for (auto x : cur) {
    p++;
    if (p > 5) break;
    t.push_back(x);
  }
  if (check(t[0], t[1], t[2]))
    ans = t[0].w + t[1].w + t[3].w;
  else
    ans = t[0].w + t[1].w + t[2].w;
  for (auto x : t) {
    for (auto y : t) {
      if (x.u == y.u || x.v == y.u || x.u == y.v || x.v == y.v) continue;
      ans = min(ans, (long long)x.w + y.w);
    }
  }
  return ans;
}
int main() {
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add(u, v, w);
  }
  printf("%lld\n", qry());
  int q;
  scanf("%d", &q);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 0) {
      int u, v;
      scanf("%d%d", &u, &v);
      del(u, v);
    } else {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add(u, v, w);
    }
    printf("%lld\n", qry());
  }
  return 0;
}
