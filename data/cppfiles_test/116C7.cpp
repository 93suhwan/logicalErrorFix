#include <bits/stdc++.h>
using namespace std;
const int M = 300005;
const int MOD = 998244353;
int read() {
  int x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int n, m, k, t, tot, f[M], a[M], in[M], out[M], cnt[M], dp[M];
int pd, zxy, sz, vis[M];
map<pair<int, int>, int> mp;
struct edge {
  int v, next;
} e[2 * M];
void add(int x, int y) {
  if (mp[make_pair(x, y)]) return;
  mp[make_pair(x, y)] = 1;
  in[y]++;
  out[x]++;
  e[++tot] = edge{y, f[x]}, f[x] = tot;
  e[++tot] = edge{x, f[y]}, f[y] = tot;
}
void dfs(int u) {
  sz++;
  vis[u] = 1;
  if (!in[u]) zxy = 1;
  if (in[u] >= 2 || out[u] >= 2) pd = 0;
  for (int i = f[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (!vis[v]) dfs(v);
  }
}
signed main() {
  n = read();
  m = read();
  k = read();
  for (int i = 1; i <= n; i++) {
    int len = read();
    for (int j = 1, ls; j <= len; j++) {
      int x = read();
      if (j > 1) add(ls, x);
      ls = x;
    }
  }
  for (int i = 1; i <= k; i++)
    if (!vis[i]) {
      pd = 1;
      zxy = sz = 0;
      dfs(i);
      if (!pd || !zxy) continue;
      a[++t] = sz;
      cnt[sz]++;
    }
  sort(a + 1, a + 1 + t);
  t = unique(a + 1, a + 1 + t) - a - 1;
  dp[0] = 1;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= t; j++)
      if (a[j] <= i) dp[i] = (dp[i] + 1ll * cnt[a[j]] * dp[i - a[j]]) % MOD;
  printf("%d\n", dp[m]);
}
