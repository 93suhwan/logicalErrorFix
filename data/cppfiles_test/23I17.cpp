#include <bits/stdc++.h>
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(long long &x) { scanf("%lld", &x); }
void sc(long long &x, long long &y) { scanf("%lld%lld", &x, &y); }
void sc(long long &x, long long &y, long long &z) {
  scanf("%lld%lld%lld", &x, &y, &z);
}
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(long long x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(long long x, long long y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(long long x, long long y, long long z) {
  printf("%lld %lld %lld\n", x, y, z);
}
void ast(long long x, long long l, long long r) { assert(x >= l && x <= r); }
using namespace std;
const int N = 4005;
int n, m, top, s[N], si[N], a[N], t[N][2];
int dp[N][N], g[N];
void update(int &x, int y) {
  if (y > x) x = y;
}
void dfs(int u) {
  dp[u][0] = dp[u][1] = 0;
  si[u] = 1;
  int v = t[u][0];
  if (v) {
    dfs(v);
    memset(g, 0, sizeof(g));
    for (int i = 0; i <= si[u]; i++)
      for (int j = 0; j <= si[v] && i + j <= m; j++)
        update(g[i + j],
               dp[u][i] + dp[v][j] + 1ll * j * (m - j) * (a[v] - a[u]));
    memcpy(dp[u], g, sizeof(g));
    si[u] += si[v];
  }
  v = t[u][1];
  if (v) {
    dfs(v);
    memset(g, 0, sizeof(g));
    for (int i = 0; i <= si[u]; i++)
      for (int j = 0; j <= si[v] && i + j <= m; j++)
        update(g[i + j],
               dp[u][i] + dp[v][j] + 1ll * j * (m - j) * (a[v] - a[u]));
    memcpy(dp[u], g, sizeof(g));
    si[u] += si[v];
  }
}
void sol(int cas) {
  sc(n, m);
  for (int i = 1; i <= n; i++) sc(a[i]);
  for (int i = 1; i <= n; i++) {
    while (top && a[s[top]] > a[i]) {
      if (a[s[top - 1]] > a[i])
        t[s[top - 1]][1] = s[top];
      else
        t[i][0] = s[top];
      top--;
    }
    s[++top] = i;
  }
  while (top > 1) t[s[top - 1]][1] = s[top], top--;
  dfs(s[top]);
  printf("%lld\n", dp[s[top]][m]);
}
int main() {
  srand(time(0));
  int t = 1, cas = 0;
  while (t--) {
    sol(++cas);
  }
}
