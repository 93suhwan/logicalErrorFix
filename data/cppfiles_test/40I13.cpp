#include <bits/stdc++.h>
using namespace std;
void dbg() { cerr << endl; }
template <typename A, typename... B>
void dbg(A x, B... y) {
  cerr << x << " ";
  dbg(y...);
}
int vis[1000000], fa[1000000], d[1000000], c[1000000], head[1000000], tot,
    f[1000000][2];
struct Edge {
  int v, next;
} edge[1000000];
void add(int x, int y) {
  edge[++tot] = Edge{y, head[x]};
  head[x] = tot;
}
void dfs(int x) {
  vis[x] = 1;
  for (register int i = head[x]; i; i = edge[i].next)
    if (!vis[edge[i].v])
      fa[edge[i].v] = x, d[edge[i].v] = d[x] + 1, dfs(edge[i].v);
}
void dfs2(int x) {
  f[x][c[x]] = 0;
  f[x][c[x] ^ 1] = 1e9;
  for (register int i = head[x]; i; i = edge[i].next)
    if (fa[edge[i].v] == x) {
      dfs2(edge[i].v);
      int g[2] = {f[x][0], f[x][1]};
      f[x][0] = min(g[0] + f[edge[i].v][0], g[1] + f[edge[i].v][1] + 1);
      f[x][1] = min(g[0] + f[edge[i].v][1], g[1] + f[edge[i].v][0]);
    }
}
int main() {
  vector<vector<int>> ans;
  int n, m, Q, x, y, tag = 1;
  scanf("%d%d", &n, &m);
  for (register int i = 1; i <= m; i++)
    scanf("%d%d", &x, &y), add(x, y), add(y, x);
  dfs(1);
  for (cin >> Q; Q--;) {
    scanf("%d%d", &x, &y);
    vector<int> p, q;
    while (d[x] > d[y]) c[x] ^= 1, p.push_back(x), x = fa[x];
    while (d[y] > d[x]) c[y] ^= 1, q.push_back(y), y = fa[y];
    while (x != y)
      c[x] ^= 1, c[y] ^= 1, p.push_back(x), q.push_back(y), x = fa[x],
                                                            y = fa[y];
    p.push_back(x);
    for (register int i = q.size() - 1; i >= 0; i--) p.push_back(q[i]);
    ans.push_back(p);
  }
  for (register int i = 1; i <= n; i++) tag &= !c[i];
  if (tag) {
    cout << "YES\n";
    for (auto x : ans) {
      cout << x.size() << "\n";
      for (auto y : x) cout << y << " ";
      cout << "\n";
    }
  } else {
    cout << "NO\n";
    dfs2(1);
    cout << min(f[1][0], f[1][1] + 1);
  }
  return 0;
}
