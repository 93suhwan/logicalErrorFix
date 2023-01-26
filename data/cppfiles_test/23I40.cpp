#include <bits/stdc++.h>
using namespace std;
int read() {
  int f = 0, s = 0;
  char c = getchar();
  while (c > '9' || c < '0') f = (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    s = (s << 3) + (s << 1) + (c ^ '0'), c = getchar();
  return f ? -s : s;
}
const int N = 4005;
int n, m;
int a[N];
int rt;
int c[N][2];
int st[N], tp = 0;
int f[N][N];
int siz[N];
void dfs(int u) {
  if (c[u][0]) dfs(c[u][0]);
  if (c[u][1]) dfs(c[u][1]);
  siz[u] = 1;
  if (c[u][0]) {
    int lw = a[c[u][0]] - a[u];
    for (int i = siz[u]; i >= 0; i--)
      for (int j = 0; j <= siz[c[u][0]]; j++)
        f[u][i + j] =
            max(f[u][i + j], f[u][i] + f[c[u][0]][j] + j * (m - j) * lw);
    siz[u] += siz[c[u][0]];
  }
  if (c[u][1]) {
    int rw = a[c[u][1]] - a[u];
    for (int i = siz[u]; i >= 0; i--)
      for (int j = 0; j <= siz[c[u][1]]; j++)
        f[u][i + j] =
            max(f[u][i + j], f[u][i] + f[c[u][1]][j] + j * (m - j) * rw);
    siz[u] += siz[c[u][1]];
  }
}
int ans = 0;
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) {
    int now = tp;
    while (now && a[i] < a[st[now]]) now--;
    if (now != tp) c[i][0] = st[now + 1];
    if (now) c[st[now]][1] = i;
    tp = now;
    st[++tp] = i;
  }
  for (int i = 1; i < tp; i++) c[st[i]][1] = st[i + 1];
  rt = st[1];
  memset(f, 0, sizeof f);
  dfs(rt);
  printf("%d", f[rt][m]);
  return 0;
}
