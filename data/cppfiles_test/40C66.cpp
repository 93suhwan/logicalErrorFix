#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
vector<int> v[N];
int f[N], fa[N], dep[N], cnt[N];
int find(int x) {
  if (f[x] == x) return x;
  return f[x] = find(f[x]);
}
void dfs(int now, int pre) {
  fa[now] = pre;
  dep[now] = dep[pre] + 1;
  for (auto to : v[now]) {
    if (to == pre) continue;
    dfs(to, now);
  }
}
struct node {
  int x, y;
};
node a[N];
vector<int> v1[N], v2[N];
void lca(int x, int y, int id) {
  int xx = x, yy = y;
  while (x != y) {
    if (dep[x] >= dep[y]) {
      cnt[x]++;
      x = fa[x];
    } else if (dep[x] <= dep[y]) {
      cnt[y]++;
      y = fa[y];
    }
  }
  int pos = x;
  x = xx, y = yy;
  while (x != pos) {
    v1[id].push_back(x);
    x = fa[x];
  }
  v1[id].push_back(pos);
  while (y != pos) {
    v2[id].push_back(y);
    y = fa[y];
  }
  reverse(v2[id].begin(), v2[id].end());
  return;
}
int ans;
void dfs2(int now, int pre) {
  if (cnt[now] & 1) ans++;
  int tot = 0;
  for (auto to : v[now]) {
    if (to == pre) continue;
    dfs2(to, now);
    if (cnt[to] & 1) tot++;
  }
  if (cnt[now] & 1) {
    if (tot >= 1) {
      ans--;
      ans -= (tot - 1) / 2;
    }
  } else {
    if (tot >= 1) {
      ans -= tot / 2;
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (find(x) != find(y)) {
      v[x].push_back(y);
      v[y].push_back(x);
    }
    f[find(x)] = find(y);
  }
  dfs(1, 0);
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    lca(a[i].x, a[i].y, i);
  }
  int f = 1;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] & 1) f = 0;
  }
  if (f) {
    printf("YES\n");
    for (int i = 1; i <= q; i++) {
      printf("%d\n", v1[i].size() + v2[i].size());
      for (auto it : v1[i]) {
        printf("%d ", it);
      }
      for (auto it : v2[i]) {
        printf("%d ", it);
      }
      printf("\n");
    }
  } else {
    printf("NO\n");
    dfs2(1, 0);
    printf("%d\n", ans);
  }
  return 0;
}
