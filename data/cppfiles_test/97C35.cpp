#include <bits/stdc++.h>
using namespace std;
struct Vertex {
  int cost;
  int depth;
  int idx;
  Vertex(){};
  Vertex(int cost, int depth, int idx) : cost(cost), depth(depth), idx(idx){};
};
bool operator<(const Vertex& a, const Vertex& b) {
  if (a.cost != b.cost) return a.cost > b.cost;
  if (a.depth != b.depth) return a.depth > b.depth;
  return a.idx < b.idx;
}
struct DSU {
  int n;
  vector<int> p;
  vector<int> top;
  int get(int x) {
    if (p[x] == x) return x;
    return p[x] = get(p[x]);
  }
  int get_top(int x) { return top[get(x)]; }
  void merge(int x, int par) { p[x] = par; }
  DSU(int k = 0) {
    n = k;
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    top = p;
  };
};
const int N = 200043;
int n;
vector<int> g[N];
int p[N], d[N], tin[N], tout[N];
int qv[N];
int qk[N];
int T = 0;
void dfs(int v = 0, int par = -1) {
  tin[v] = T++;
  p[v] = par;
  if (par == -1)
    d[v] = 0;
  else
    d[v] = d[par] + 1;
  for (auto x : g[v])
    if (x != par) dfs(x, v);
  tout[v] = T;
}
pair<long long, long long> tree[4 * N];
pair<long long, long long> operator+(const pair<long long, long long>& a,
                                     const pair<long long, long long>& b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
pair<long long, long long> get(int v, int l, int r, int L, int R) {
  if (L >= R) return {0, 0};
  if (l == L && r == R) return tree[v];
  int m = (l + r) / 2;
  return get(v * 2 + 1, l, m, L, min(R, m)) +
         get(v * 2 + 2, m, r, max(m, L), R);
}
void add(int v, int l, int r, int pos, pair<long long, long long> val) {
  if (l == r - 1)
    tree[v] = tree[v] + val;
  else {
    int m = (l + r) / 2;
    if (pos < m)
      add(v * 2 + 1, l, m, pos, val);
    else
      add(v * 2 + 2, m, r, pos, val);
    tree[v] = tree[v] + val;
  }
}
pair<long long, long long> get_vertex_value(int v) {
  return get(0, 0, n, tin[v], tout[v]);
}
void add_on_path(int x, int y, pair<long long, long long> val) {
  add(0, 0, n, tin[x], val);
  if (p[y] != -1) add(0, 0, n, tin[p[y]], make_pair(-val.first, -val.second));
}
int calculate_cost(int v, int correction) {
  pair<long long, long long> res = get_vertex_value(v);
  long long k = (res.first + res.second) / (res.second + 1) - 1;
  return k;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d", &qv[i], &qk[i]);
    --qv[i];
  }
  dfs();
  DSU dsu(n);
  vector<long long> ans(q);
  set<Vertex> pq;
  vector<Vertex> curv(n);
  for (int i = 0; i < n; i++) {
    int count_children = g[i].size();
    if (i != 0) count_children--;
    add_on_path(i, i, make_pair((long long)(count_children), 0ll));
    if (i != 0) {
      curv[i] = Vertex(calculate_cost(i, 200000), d[i], i);
      pq.insert(curv[i]);
    }
  }
  for (int i = 0; i < q; i++) pq.insert(Vertex(qk[i], -1, i));
  while (!pq.empty()) {
    Vertex z = *pq.begin();
    pq.erase(pq.begin());
    if (z.depth == -1) {
      auto res = get_vertex_value(qv[z.idx]);
      ans[z.idx] = res.first - res.second * z.cost;
    } else {
      int v = z.idx;
      int pv = p[v];
      int newtop = dsu.get_top(pv);
      pair<long long, long long> val = get_vertex_value(v);
      val.second++;
      val.first--;
      if (newtop != 0) pq.erase(curv[newtop]);
      add_on_path(pv, newtop, val);
      if (newtop != 0) curv[newtop].cost = calculate_cost(newtop, z.cost);
      if (newtop != 0) pq.insert(curv[newtop]);
      dsu.merge(v, pv);
    }
  }
  for (int i = 0; i < q; i++) printf("%lld\n", ans[i]);
}
