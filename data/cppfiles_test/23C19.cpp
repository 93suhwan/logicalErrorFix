#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - 48;
    c = getchar();
  }
  return flag ? x : -x;
}
const int N = 4e3 + 7;
struct Node {
  int ls, rs;
} t[N];
long long dp[N][N];
int a[N], top = 0, st[N], sz[N], n, m;
void dfs(int u) {
  sz[u] = 1;
  if (t[u].ls) {
    dfs(t[u].ls);
    const int v = t[u].ls;
    for (int i = sz[u]; ~i; i--)
      for (int j = 0, rg = min(sz[v], m - i); j <= rg; j++)
        dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[v][j] +
                                             1ll * j * (m - j) * (a[v] - a[u]));
    sz[u] += sz[v];
  }
  if (t[u].rs) {
    dfs(t[u].rs);
    const int v = t[u].rs;
    for (int i = sz[u]; ~i; i--)
      for (int j = 0, rg = min(sz[v], m - i); j <= rg; j++)
        dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[v][j] +
                                             1ll * j * (m - j) * (a[v] - a[u]));
    sz[u] += sz[v];
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    int ret = 0;
    while (top && a[st[top]] >= a[i]) ret = st[top--];
    if (ret) t[i].ls = ret;
    if (top) t[st[top]].rs = i;
    st[++top] = i;
  }
  dfs(st[1]);
  printf("%lld", dp[st[1]][m]);
}
