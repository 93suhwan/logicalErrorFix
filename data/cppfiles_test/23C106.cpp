#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long f = 0, s = 0;
  char c = getchar();
  while (c > '9' || c < '0') f = (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    s = (s << 3) + (s << 1) + (c ^ '0'), c = getchar();
  return f ? -s : s;
}
const long long N = 4005;
long long n, m;
long long a[N];
long long rt;
long long c[N][2];
long long st[N], tp = 0;
long long f[N][N];
long long siz[N];
void dfs(long long u) {
  if (c[u][0]) dfs(c[u][0]);
  if (c[u][1]) dfs(c[u][1]);
  siz[u] = 1;
  if (c[u][0]) {
    long long lw = a[c[u][0]] - a[u];
    for (long long i = siz[u]; i >= 0; i--)
      for (long long j = 0; j <= siz[c[u][0]]; j++)
        f[u][i + j] =
            max(f[u][i + j], f[u][i] + f[c[u][0]][j] + j * (m - j) * lw);
    siz[u] += siz[c[u][0]];
  }
  if (c[u][1]) {
    long long rw = a[c[u][1]] - a[u];
    for (long long i = siz[u]; i >= 0; i--)
      for (long long j = 0; j <= siz[c[u][1]]; j++)
        f[u][i + j] =
            max(f[u][i + j], f[u][i] + f[c[u][1]][j] + j * (m - j) * rw);
    siz[u] += siz[c[u][1]];
  }
}
long long ans = 0;
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) {
    long long now = tp;
    while (now && a[i] < a[st[now]]) now--;
    if (now != tp) c[i][0] = st[now + 1];
    if (now) c[st[now]][1] = i;
    tp = now;
    st[++tp] = i;
  }
  for (long long i = 1; i < tp; i++) c[st[i]][1] = st[i + 1];
  rt = st[1];
  memset(f, 0, sizeof f);
  dfs(rt);
  printf("%lld", f[rt][m]);
  return 0;
}
