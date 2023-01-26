#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
int n, m, q;
int cnt;
int u, v;
int c[MAXN], d[MAXN];
int tot[MAXN], sum;
int vis[MAXN];
int dep[MAXN], fa[MAXN];
int f[MAXN][21];
stack<int> s;
struct Node {
  int v;
  Node *next;
} * h[MAXN], pool[MAXN * 2];
void Adde(int u, int v) {
  Node *p = &pool[++cnt];
  p->v = v;
  p->next = h[u];
  h[u] = p;
}
void Dfs(int u) {
  vis[u] = 1;
  dep[u] = dep[fa[u]] + 1;
  for (Node *p = h[u]; p; p = p->next) {
    if (vis[p->v] == 0) {
      fa[p->v] = u;
      Dfs(p->v);
    }
  }
}
int Ask(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 20; i >= 0; --i)
    if (dep[f[u][i]] >= dep[v]) u = f[u][i];
  if (u == v) return u;
  for (int i = 20; i >= 0; --i)
    if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
  return fa[u];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    Adde(u, v);
    Adde(v, u);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d", &c[i], &d[i]);
    tot[c[i]]++;
    tot[d[i]]++;
  }
  for (int i = 1; i <= n; ++i) sum += (tot[i] % 2);
  if (sum) {
    printf("No\n%d\n", sum / 2);
    return 0;
  }
  printf("Yes\n");
  Dfs(1);
  for (int i = 1; i <= n; ++i) f[i][0] = fa[i];
  for (int i = 1; i <= 20; ++i)
    for (int j = 1; j <= n; ++j) f[j][i] = f[f[j][i - 1]][i - 1];
  for (int i = 1; i <= q; ++i) {
    int lca = Ask(c[i], d[i]);
    printf("%d\n", dep[c[i]] - dep[lca] + dep[d[i]] - dep[lca] + 1);
    while (c[i] != lca) {
      printf("%d ", c[i]);
      c[i] = fa[c[i]];
    }
    printf("%d ", lca);
    while (d[i] != lca) {
      s.push(d[i]);
      d[i] = fa[d[i]];
    }
    while (!s.empty()) {
      int ans = s.top();
      s.pop();
      printf("%d ", ans);
    }
    printf("\n");
  }
  return 0;
}
