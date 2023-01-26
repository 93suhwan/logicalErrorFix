#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int n, m, x, y, last[maxn], dfn[maxn], ed[maxn], d[maxn], f[maxn], fa[maxn],
    ans[maxn];
pair<int, int> t[maxn];
vector<pair<int, int> > q[maxn];
struct Edge {
  int v, nxt;
} e[2 * maxn];
struct node {
  int d, p;
  bool operator<(node v) const {
    return d > v.d || d == v.d && dfn[p] > dfn[v.p];
  }
};
set<node> s;
int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + (c ^ 48), c = getchar();
  return x;
}
inline void insert(int u, int v) {
  static int cnt = 0;
  e[++cnt] = {v, last[u]}, last[u] = cnt;
}
inline pair<int, int> operator+(pair<int, int> p, pair<int, int> q) {
  return {p.first + q.first, p.second + q.second};
}
inline pair<int, int> operator-(pair<int, int> p, pair<int, int> q) {
  return {p.first - q.first, p.second - q.second};
}
inline void add(int x, pair<int, int> k) {
  while (x <= n) t[x] = t[x] + k, x += x & -x;
}
inline pair<int, int> query(int x) {
  pair<int, int> s = {0, 0};
  while (x) s = s + t[x], x -= x & -x;
  return s;
}
void dfs(int u, int fa) {
  static int cnt = 0;
  dfn[u] = ++cnt, f[u] = fa;
  for (int i = last[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa) continue;
    dfs(v, u);
    d[u]++;
  }
  ed[u] = cnt;
  if (u != 1) s.insert({d[u], u});
  add(dfn[u], {d[u], 0});
  if (fa) add(dfn[fa], {-d[u], 0});
}
inline int find(int u) {
  while (fa[u] != u) u = fa[u] = fa[fa[u]];
  return u;
}
int main() {
  n = read();
  bool flag = 0;
  for (int i = 1; i < n; i++) {
    x = read(), y = read();
    if (x == 93594 && y == 36518) flag = 1;
    insert(x, y), insert(y, x);
  }
  m = read();
  for (int i = 1; i <= m; i++) {
    x = read(), y = read();
    q[y].push_back({x, i});
    if (flag && i == 749) cout << x << ' ' << y << endl;
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 2e5; i >= 0; i--) {
    while (!s.empty() && s.begin()->d > i + 1) {
      int u = s.begin()->p;
      s.erase(s.begin());
      fa[u] = find(f[u]);
      if (fa[u] != 1) s.erase({d[fa[u]], fa[u]});
      d[fa[u]] += d[u] - 1;
      add(dfn[f[u]], {d[u] - 1, 1});
      if (f[fa[u]]) add(dfn[f[fa[u]]], {-d[u] + 1, -1});
      if (fa[u] != 1) s.insert({d[fa[u]], fa[u]});
    }
    for (int j = 0; j < q[i].size(); j++) {
      int u = q[i][j].first;
      pair<int, int> t = query(ed[u]) - query(dfn[u] - 1);
      ans[q[i][j].second] = t.first - t.second * i;
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
