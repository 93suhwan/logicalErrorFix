#include <bits/stdc++.h>
constexpr int Maxn = 2e5 + 7;
constexpr int Maxm = 1e6 + 7;
constexpr int Mod = 1e9 + 7;
int n, k, sum, root;
void add(int bit[], int p, int v) {
  for (; p < Maxn; p += p & -p) bit[p] = (bit[p] + v) % Mod;
}
int query(int bit[], int p) {
  int res = 0;
  for (; p; p -= p & -p) res = (res + bit[p]) % Mod;
  return res;
}
struct Edge {
  int nxt, to, w;
} e[Maxn << 1];
int head[Maxn], edge_cnt, res;
inline void add_edge(int u, int v, int w) {
  e[++edge_cnt].to = v;
  e[edge_cnt].nxt = head[u];
  e[edge_cnt].w = w;
  head[u] = edge_cnt;
}
int a[Maxn], siz[Maxn], f[Maxn];
int del[Maxn];
void getroot(int u, int fa) {
  siz[u] = 1;
  f[u] = 0;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (!del[v] && v != fa) {
      getroot(v, u);
      siz[u] += siz[v];
      f[u] = std::max(f[u], siz[v]);
    }
  }
  f[u] = std::max(f[u], sum - siz[u]);
  if (f[u] < f[root]) root = u;
}
int val[2][Maxn], num[2][Maxn];
void DFS(int u, int fa, int rcol, int col, int nxt, int tot, int opt) {
  tot = (tot + a[u]) % Mod;
  if (opt == 0) {
    if (k >= nxt) {
      int cnt = query(num[rcol], k - nxt + 1);
      int cur = query(val[rcol], k - nxt + 1);
      res = (res + 1LL * cnt * tot % Mod) % Mod;
      res = (res + cur) % Mod;
    }
    if (k >= nxt + 1) {
      int cnt = query(num[rcol ^ 1], k - nxt);
      int cur = query(val[rcol ^ 1], k - nxt);
      res = (res + 1LL * cnt * tot % Mod) % Mod;
      res = (res + cur) % Mod;
    }
    if (k >= nxt) res = (res + tot) % Mod;
  } else if (opt == 1) {
    add(num[rcol], nxt + 1, 1);
    add(val[rcol], nxt + 1, tot);
  } else {
    add(num[rcol], nxt + 1, Mod - 1);
    add(val[rcol], nxt + 1, Mod - tot);
  }
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to, w = e[i].w;
    if (del[v] || v == fa) continue;
    int nxtstp = nxt;
    if (w != col) ++nxtstp;
    DFS(v, u, rcol, w, nxtstp, tot, opt);
  }
}
void solve(int u) {
  del[u] = 1;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to, w = e[i].w;
    if (!del[v]) {
      DFS(v, u, w, w, 0, a[u], 0);
      DFS(v, u, w, w, 0, 0, 1);
    }
  }
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to, w = e[i].w;
    if (!del[v]) DFS(v, u, w, w, 0, 0, -1);
  }
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (!del[v]) {
      root = 0, sum = siz[v];
      getroot(v, 0);
      solve(root);
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  f[0] = sum = n;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1, u, v, w; i <= n - 1; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    add_edge(u, v, w), add_edge(v, u, w);
  }
  getroot(1, 0);
  solve(root);
  for (int i = 1; i <= n; ++i) res = (res + a[i]) % Mod;
  printf("%d\n", res);
}
