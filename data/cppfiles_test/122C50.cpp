#include <bits/stdc++.h>
using namespace std;
bool fl, vis[200005];
int en, d[200005], head[200005];
struct edge {
  int u, v, w, nxt;
} e[200005 * 4], e0[200005];
void dfs(int);
void adde(int, int, int);
int calc(int x) {
  int ans = 0;
  while (x) {
    ans ^= x & 1;
    x >>= 1;
  }
  return ans;
}
int main() {
  int i, k, t, n, m, u, v, w;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    fl = 0;
    en = 0;
    memset(vis, 0, n + 1);
    memset(head, 0, 4 * (n + 1));
    for (i = 1; i < n; ++i) {
      scanf("%d %d %d", &u, &v, &w);
      e0[i].u = u;
      e0[i].v = v;
      e0[i].w = w;
      if (w != -1) {
        k = calc(w);
        adde(u, v, k);
        adde(v, u, k);
      }
    }
    for (i = 1; i <= m; ++i) {
      scanf("%d %d %d", &u, &v, &w);
      adde(u, v, w);
      adde(v, u, w);
    }
    for (i = 1; i <= n; ++i)
      if (!vis[i]) {
        d[i] = 0;
        dfs(i);
      }
    if (fl) {
      puts("NO");
      continue;
    }
    for (i = 1; i < n; ++i)
      if (e0[i].w == -1) {
        u = e0[i].u;
        v = e0[i].v;
        if (d[u] == d[v])
          e0[i].w = 0;
        else
          e0[i].w = 1;
      }
    puts("YES");
    for (i = 1; i < n; ++i) printf("%d %d %d\n", e0[i].u, e0[i].v, e0[i].w);
  }
  return 0;
}
void dfs(int u) {
  int i, v;
  vis[u] = 1;
  for (i = head[u]; i; i = e[i].nxt)
    if (!vis[v = e[i].v]) {
      d[v] = (d[u] ^ e[i].w);
      dfs(v);
    } else
      fl |= d[v] != (d[u] ^ e[i].w);
}
void adde(int u, int v, int w) {
  e[++en].v = v;
  e[en].w = w;
  e[en].nxt = head[u];
  head[u] = en;
}
