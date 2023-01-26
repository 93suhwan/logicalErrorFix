#include <bits/stdc++.h>
int first[1000010], next[1000010], tail[1000010], edge, d[1000010], p[1000010];
void addedge(int u, int v) {
  edge++;
  next[edge] = first[u];
  first[u] = edge;
  tail[edge] = v;
}
void dfs(int u, int par, int dep) {
  d[u] = dep;
  p[u] = par;
  for (int e = first[u]; e; e = next[e])
    if (tail[e] != par) {
      int v = tail[e];
      dfs(v, u, dep + 1);
    }
}
int t[1000010];
bool comp1(int x, int y) { return d[x] > d[y]; }
bool comp2(int x, int y) { return x > y; }
int count[1000010];
bool vis[1000010];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  edge = 0;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  dfs(1, 0, 1);
  for (int i = 1; i <= n; i++) t[i] = i;
  std::sort(t + 1, t + 1 + n, comp1);
  for (int i = 1; i <= n; i++) {
    count[i] = 0;
    int u = t[i];
    while (u && !vis[u]) {
      vis[u] = true;
      count[i]++;
      u = p[u];
    }
  }
  std::sort(count + 1, count + 1 + n, comp2);
  int sum = 0;
  for (int i = 1; i <= k; i++) {
    sum += count[i];
    int blue = std::min(n / 2, n - sum);
    printf("%d\n", (n - i - blue) * (i - blue));
  }
  return 0;
}
