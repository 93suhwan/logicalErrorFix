#include <bits/stdc++.h>
using namespace std;
const int N = 200000, LOGN = 18;
int n, m, val[N + 9];
struct edge {
  int x, y, val, cost;
} a[N + 9];
vector<edge> E[N + 9];
struct query {
  int pos, val, id, Ans1, Ans2;
} b[N + 9];
int dep[N + 9], fth[N + 9][LOGN + 9], mx[N + 9][LOGN + 9];
void dfs(int now) {
  for (int i = 1; fth[now][i - 1]; i++)
    fth[now][i] = fth[fth[now][i - 1]][i - 1],
    mx[now][i] = max(mx[now][i - 1], mx[fth[now][i - 1]][i - 1]);
  for (auto e : E[now])
    if (fth[now][0] != e.y)
      dep[e.y] = dep[now] + 1, fth[e.y][0] = now, mx[e.y][0] = e.cost, dfs(e.y);
}
int getcost(int a, int b) {
  int res = 0;
  if (dep[a] < dep[b]) swap(a, b);
  for (int i = LOGN; i >= 0; i--)
    if (fth[a][i] && dep[fth[a][i]] >= dep[b])
      res = max(res, mx[a][i]), a = fth[a][i];
  for (int i = LOGN; i >= 0; i--)
    if (fth[a][i] != fth[b][i])
      res = max(res, max(mx[a][i], mx[b][i])), a = fth[a][i], b = fth[b][i];
  if (a != b) res = max(res, max(mx[a][0], mx[b][0]));
  return res;
}
int rt[N + 9], mxcost[N + 9];
int find(int x) { return rt[x] == x ? x : rt[x] = find(rt[x]); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", val + i);
  for (int i = 1; i < n; i++)
    scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].val, &a[i].cost),
        E[a[i].x].push_back(a[i]), swap(a[i].x, a[i].y),
        E[a[i].x].push_back(a[i]);
  for (int i = 1; i <= m; i++) scanf("%d%d", &b[i].val, &b[i].pos), b[i].id = i;
  sort(a + 1, a + n, [&](edge a, edge b) { return a.val > b.val; }),
      sort(b + 1, b + 1 + m, [&](query a, query b) { return a.val > b.val; });
  dfs(1);
  for (int i = 1; i <= n; i++) rt[i] = i;
  for (int i = 1, j = 1; i <= m; i++) {
    while (j < n && a[j].val >= b[i].val) {
      int u = find(a[j].x), v = find(a[j].y);
      if (val[u] == val[v])
        mxcost[u] = max(getcost(u, v), max(mxcost[u], mxcost[v]));
      else if (val[u] < val[v])
        swap(u, v);
      rt[v] = u;
      j++;
    }
    int p = find(b[i].pos);
    b[i].Ans1 = val[p], b[i].Ans2 = max(mxcost[p], getcost(p, b[i].pos));
  }
  sort(b + 1, b + 1 + m, [&](query a, query b) { return a.id < b.id; });
  for (int i = 1; i <= m; i++) printf("%d %d\n", b[i].Ans1, b[i].Ans2);
  return 0;
}
