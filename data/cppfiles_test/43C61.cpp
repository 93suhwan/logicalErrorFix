#include <bits/stdc++.h>
using namespace std;
struct edge {
  int x, y, z;
} t[400001], p[400001];
int n, m, x, y, z, w, sum, cnt, f[200001], h[200001], fa[200001],
    mn[200001][21], g[200001][21], ss[200001], dep[200001], ans1[200001],
    ans2[200001];
bool cmp(edge a, edge b) {
  if (a.z == b.z) return a.y < b.y;
  return a.z > b.z;
}
int father(int a) {
  if (fa[a] == a) return a;
  fa[a] = father(fa[a]);
  return fa[a];
}
void link(int a, int b, int c) {
  cnt++;
  t[cnt].x = b;
  t[cnt].y = h[a];
  t[cnt].z = c;
  h[a] = cnt;
}
void dfs(int a) {
  for (int i = 1; i <= 20; i++) {
    g[a][i] = g[g[a][i - 1]][i - 1];
    mn[a][i] = max(mn[a][i - 1], mn[g[a][i - 1]][i - 1]);
  }
  for (int i = h[a]; i; i = t[i].y) {
    if (!dep[t[i].x]) {
      dep[t[i].x] = dep[a] + 1;
      g[t[i].x][0] = a;
      mn[t[i].x][0] = t[i].z;
      dfs(t[i].x);
    }
  }
}
int find(int a, int b) {
  int s = 0;
  if (dep[a] > dep[b]) {
    for (int i = 20; i >= 0; i--) {
      if (dep[g[a][i]] >= dep[b]) {
        s = max(s, mn[a][i]);
        a = g[a][i];
      }
    }
  }
  if (dep[a] < dep[b]) {
    for (int i = 20; i >= 0; i--) {
      if (dep[g[b][i]] >= dep[a]) {
        s = max(s, mn[b][i]);
        b = g[b][i];
      }
    }
  }
  if (a == b) return s;
  for (int i = 20; i >= 0; i--) {
    if (g[a][i] != g[b][i]) {
      s = max(s, max(mn[a][i], mn[b][i]));
      a = g[a][i];
      b = g[b][i];
    }
  }
  return max(s, max(mn[a][0], mn[b][0]));
}
void merge(int a, int b) {
  int fx = father(a);
  int fy = father(b);
  if (f[fx] < f[fy]) swap(fx, fy);
  if (f[fx] == f[fy]) ss[fx] = max(find(fx, fy), max(ss[fx], ss[fy]));
  fa[fy] = fx;
}
void solve(int a, int c) {
  int fx = father(a);
  ans1[c] = f[fx];
  ans2[c] = max(find(a, fx), ss[fx]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &f[i]);
  for (int i = 1; i < n; i++) {
    scanf("%d%d%d%d", &x, &y, &z, &w);
    link(x, y, w);
    link(y, x, w);
    sum++;
    p[sum].x = x;
    p[sum].y = y;
    p[sum].z = z;
  }
  for (int i = 1; i <= m; i++) {
    sum++;
    scanf("%d%d", &p[sum].z, &p[sum].x);
    p[sum].y = n + i;
  }
  sort(p + 1, p + sum + 1, cmp);
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    ss[i] = 0;
  }
  dep[1] = 1;
  dfs(1);
  for (int i = 1; i <= sum; i++) {
    if (p[i].y <= n) {
      merge(p[i].x, p[i].y);
    } else {
      solve(p[i].x, p[i].y - n);
    }
  }
  for (int i = 1; i <= m; i++) printf("%d %d\n", ans1[i], ans2[i]);
}
