#include <bits/stdc++.h>
using namespace std;
int head[200000 + 5], cnt, fa[200000 + 5], tot;
struct node {
  int id, dep;
} q[200000 + 5];
struct edge {
  int end, next;
} e[400000 + 5];
void add_edge(int u, int v) {
  e[++cnt].end = v;
  e[cnt].next = head[u];
  head[u] = cnt;
}
void dfs(int u, int dep) {
  tot++;
  q[tot].id = u;
  q[tot].dep = dep;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].end;
    if (fa[u] == v) continue;
    fa[v] = u;
    dfs(v, dep + 1);
  }
}
bool cmp(node A, node B) { return A.dep > B.dep; }
bool vis[200000 + 5];
int main() {
  int n, k, i, j, sum = 0;
  long long ans = 0;
  scanf("%d%d", &n, &k);
  for (i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
  }
  dfs(1, 0);
  sort(q + 1, q + cnt + 1, cmp);
  for (i = 1; i <= n; i++) {
    int u = q[i].id;
    q[i].dep = 0;
    while (u && !vis[u]) vis[u] = true, q[i].dep++, u = fa[u];
  }
  sort(q + 1, q + cnt + 1, cmp);
  for (i = 1; i <= k; i++)
    sum += q[i].dep - 1, ans = max(ans, 1ll * sum * (i - (n - i - sum)));
  if (ans == 0) ans = -1;
  printf("%lld\n", ans);
}
