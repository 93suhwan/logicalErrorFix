#include <bits/stdc++.h>
using namespace std;
int n, a[200010];
vector<int> anc[200010];
vector<int> v;
int tot, h[6000010];
struct node {
  int v, nxt;
} e[12000010];
void add(int u, int v) {
  e[++tot] = (node){v, h[u]};
  h[u] = tot;
}
int dis[6000010];
bool vis[6000010];
void dfs(int u, int fa) {
  dis[u] = dis[fa] + 1;
  vis[u] = 1;
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa || vis[v]) continue;
    dfs(v, u);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    int cur = a[i];
    anc[i].push_back(cur);
    for (int j = 30; j >= 1; j--)
      if ((1 << j - 1) < cur && (1 << j) > cur)
        cur = (1 << j) - cur, anc[i].push_back(cur);
    if (cur != 0) anc[i].push_back(0);
    for (auto j : anc[i]) v.push_back(j);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)anc[i].size(); j++)
      anc[i][j] = lower_bound(v.begin(), v.end(), anc[i][j]) - v.begin() + 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j + 1 < (int)anc[i].size(); j++)
      add(anc[i][j], anc[i][j + 1]), add(anc[i][j + 1], anc[i][j]);
  dis[0] = -1;
  dfs(1, 0);
  int mx = 1;
  for (int i = 1; i <= n; i++)
    if (dis[anc[i][0]] > dis[anc[mx][0]]) mx = i;
  memset(dis, 0, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  dis[0] = -1;
  dfs(anc[mx][0], 0);
  int mx2 = 1;
  for (int i = 1; i <= n; i++)
    if (dis[anc[i][0]] > dis[anc[mx2][0]]) mx2 = i;
  printf("%d %d %d", mx, mx2, dis[anc[mx2][0]]);
  return 0;
}
