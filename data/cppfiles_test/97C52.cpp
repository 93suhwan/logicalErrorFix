#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int n, m, x, y, last[maxn], dfn[maxn], ed[maxn], d[maxn], cnt[maxn], r[maxn],
    f[maxn], fa[maxn], ans[maxn];
pair<int, int> t[maxn];
vector<pair<int, int> > q[maxn];
struct Edge {
  int v, nxt;
} e[2 * maxn];
struct node {
  int p;
  bool operator<(node v) const {
    return r[p] > r[v.p] || r[p] == r[v.p] && dfn[p] > dfn[v.p];
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
inline int calc(int u) { return (d[u] - 1) / (cnt[u] + 1); }
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
  r[u] = d[u] - 1;
  if (u != 1) s.insert({u});
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
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 2e5; i >= 0; i--) {
    int u;
    while (!s.empty() && (u = s.begin()->p) && r[u] == i) {
      s.erase(s.begin());
      fa[u] = find(f[u]);
      cnt[u]++;
      add(dfn[f[u]], {d[u] - 1, cnt[u]});
      int t = fa[u];
      if (f[t]) add(dfn[f[t]], {-d[u] + 1, -cnt[u]});
      if (t == 1) continue;
      s.erase({t});
      d[t] += d[u] - 1, cnt[t] += cnt[u], r[t] = (d[t] - 1) / (cnt[t] + 1);
      s.insert({t});
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
