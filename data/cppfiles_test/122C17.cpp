#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m;
int col[N];
bool vis[N];
struct Edge {
  int a, b, c;
  Edge() {}
  Edge(int a, int b, int c) : a(a), b(b), c(c) {}
} edge[N << 1];
void dfs(int u, int c, bool &flag, vector<pair<int, bool> > *G) {
  vis[u] = true;
  col[u] = c;
  for (pair<int, bool> i : G[u]) {
    if (vis[i.first])
      flag &= (c ^ i.second) == col[i.first];
    else
      dfs(i.first, c ^ i.second, flag, G);
  }
}
inline void solve() {
  scanf("%d%d", &n, &m);
  vector<pair<int, bool> > G[n + 10];
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    edge[i] = Edge(a, b, c);
    if (c == -1) continue;
    int p = __builtin_popcount(c) % 2;
    G[a].push_back(make_pair(b, p));
    G[b].push_back(make_pair(a, p));
  }
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int p = __builtin_popcount(c) % 2;
    G[a].push_back(make_pair(b, p));
    G[b].push_back(make_pair(a, p));
  }
  bool flag = true;
  memset(col, 0, sizeof(col));
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i, 0, flag, G);
  }
  if (!flag)
    puts("NO");
  else {
    puts("YES");
    for (int i = 1; i < n; i++) {
      Edge e = edge[i];
      if (~e.c)
        printf("%d %d %d\n", e.a, e.b, e.c);
      else
        printf("%d %d %d\n", e.a, e.b, col[e.a] ^ col[e.b]);
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
}
