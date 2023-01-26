#include <bits/stdc++.h>
int n, m;
int p[1000010], size[1000010];
bool state[1000010];
int f[1000010][21];
int dep[1000010];
int x[1000010], y[1000010];
int find(int x) {
  if (p[x] == x) return x;
  return p[x] = find(p[x]);
}
int edge;
int first[1000010], next[2000010], tail[2000010];
void addedge(int u, int v) {
  edge++;
  next[edge] = first[u];
  first[u] = edge;
  tail[edge] = v;
}
void dfs(int u, int p, int depth) {
  dep[u] = depth;
  f[u][0] = p;
  for (int i = 1; i <= 20; i++) f[u][i] = f[f[u][i - 1]][i - 1];
  for (int e = first[u]; e; e = next[e]) {
    int v = tail[e];
    if (v != p) {
      dfs(v, u, depth + 1);
    }
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) return lca(v, u);
  for (int i = 20; i >= 0; i--)
    if (dep[f[u][i]] >= dep[v]) u = f[u][i];
  for (int i = 20; i >= 0; i--)
    if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
  if (u != v) u = f[u][0], v = f[v][0];
  return u;
}
int main() {
  edge = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    size[i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    int pu = find(u), pv = find(v);
    if (pu != pv) {
      if (size[pu] < size[pv]) std::swap(pu, pv);
      p[pv] = pu;
      size[pu] += size[pv];
      addedge(u, v);
      addedge(v, u);
    }
  }
  dfs(1, 0, 1);
  for (int i = 1; i <= n; i++) state[i] = true;
  int Q;
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d", &x[i], &y[i]);
    state[x[i]] = !state[x[i]];
    state[y[i]] = !state[y[i]];
  }
  int count = 0;
  for (int i = 1; i <= n; i++)
    if (!state[i]) count++;
  if (count) {
    printf("NO\n%d\n", count / 2);
  } else {
    printf("YES\n");
    for (int i = 1; i <= Q; i++) {
      int u = x[i], v = y[i];
      int w = lca(u, v);
      std::vector<int> vec1, vec2;
      while (u != w) {
        vec1.push_back(u);
        u = f[u][0];
      }
      while (v != w) {
        vec2.push_back(v);
        v = f[v][0];
      }
      printf("%d ", vec1.size() + 1 + vec2.size());
      for (int j = 0; j < vec1.size(); j++) printf("%d ", vec1[j]);
      printf("%d ", w);
      for (int j = vec2.size() - 1; j >= 0; j--) printf("%d ", vec2[j]);
      printf("\n");
    }
  }
  return 0;
}
