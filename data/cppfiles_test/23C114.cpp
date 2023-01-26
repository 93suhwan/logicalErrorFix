#include <bits/stdc++.h>
using namespace std;
const int M = 4005;
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
int n, m, t, a[M], s[M], siz[M], ch[M][2];
long long dp[M][M];
void upd(long long &x, long long y) { x = max(x, y); }
void dfs(int u) {
  dp[u][0] = 0;
  if (!u) return;
  int ls = ch[u][0], rs = ch[u][1];
  dfs(ls);
  dfs(rs);
  siz[u] = 1 + siz[ls] + siz[rs];
  for (int i = 0; i <= siz[ls]; i++)
    for (int j = 0; j <= siz[rs]; j++)
      upd(dp[u][i + j], dp[ls][i] + dp[rs][j] - 2ll * i * j * a[u]);
  for (int i = siz[u] - 1; i >= 0; i--)
    upd(dp[u][i + 1], dp[u][i] + (m - 2 * i - 1ll) * a[u]);
}
signed main() {
  n = read();
  m = read();
  memset(dp, -0x3f, sizeof dp);
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    while (t > 0 && a[s[t]] > a[i]) ch[i][0] = s[t--];
    if (t) ch[s[t]][1] = i;
    s[++t] = i;
  }
  dfs(s[1]);
  printf("%lld\n", dp[s[1]][m]);
}
