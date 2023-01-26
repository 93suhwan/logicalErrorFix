#include <bits/stdc++.h>
template <class T>
inline T read() {
  T r = 0, f = 0;
  char c;
  while (!isdigit(c = getchar())) f |= (c == '-');
  while (isdigit(c)) r = (r << 1) + (r << 3) + (c ^ 48), c = getchar();
  return f ? -r : r;
}
template <class T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
struct E {
  int v, nxt;
  E() {}
  E(int v, int nxt) : v(v), nxt(nxt) {}
} e[202202 << 1];
int n, m, s_e, head[202202], dis[202202];
inline void a_e(int u, int v) {
  e[++s_e] = E(v, head[u]);
  head[u] = s_e;
}
int son[202202];
void dfs(int u, int fa) {
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa) continue;
    dfs(v, u);
    if (dis[u] < dis[v]) dis[u] = dis[v], son[u] = v;
  }
  dis[u]++;
}
int len[202202];
int s, d[202202];
void DFS(int u, int t) {
  len[u] = dis[t];
  if (!son[u]) {
    d[++s] = len[u];
    return;
  }
  DFS(son[u], t);
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (!len[v]) DFS(v, v);
  }
}
int main() {
  n = read<int>();
  m = read<int>();
  for (int i = 1; i < n; i++) {
    int u = read<int>();
    int v = read<int>();
    a_e(u, v), a_e(v, u);
  }
  dfs(1, 0), DFS(1, 1);
  if (s < m) {
    long long ans = 0;
    for (int i = s; i <= m; i++) ans = max(ans, 1ll * i * (n - i));
    return printf("%lld\n", ans), 0;
  }
  std::sort(d + 1, d + 1 + s);
  std::reverse(d + 1, d + 1 + s);
  long long sum = 0;
  for (int i = 1; i <= m; i++) sum += d[i];
  printf("%lld\n", 1ll * (sum - m) * (sum + m - n));
  return 0;
}
