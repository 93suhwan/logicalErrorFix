#include <bits/stdc++.h>
using namespace std;
int n, m, q;
vector<int> edge[300005];
pair<int, int> query[300005];
int djs[300005];
bool vis[300005];
int Get(int x) {
  if (djs[x] == x) return x;
  return djs[x] = Get(djs[x]);
}
vector<int> path;
bool dfs(int p, int d, int f) {
  path.push_back(p);
  if (p == d) return true;
  for (int it : edge[p]) {
    if (it == f) continue;
    if (dfs(it, d, p)) return true;
  }
  path.pop_back();
  return false;
}
signed main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) djs[i] = i;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (Get(u) != Get(v)) {
      edge[u].push_back(v);
      edge[v].push_back(u);
      djs[Get(u)] = Get(v);
    }
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d %d", &query[i].first, &query[i].second);
    vis[query[i].first] ^= true;
    vis[query[i].second] ^= true;
  }
  int num = 0;
  for (int i = 1; i <= n; i++)
    if (vis[i]) num++;
  if (num == 0) {
    printf("YES\n");
    for (int i = 1; i <= q; i++) {
      dfs(query[i].first, query[i].second, 0);
      printf("%d\n", path.size());
      for (int j = 0; j < path.size(); j++) {
        printf("%d", path[j]);
        if (j + 1 == path.size())
          printf("\n");
        else
          printf(" ");
      }
      path.clear();
    }
  } else {
    printf("NO\n");
    printf("%d\n", num / 2);
  }
  return 0;
}
