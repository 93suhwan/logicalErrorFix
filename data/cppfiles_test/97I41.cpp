#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 100, M = 450;
int n, q, dp[N][M], B, ans[N], sz[N], f[M];
vector<int> e[N];
struct node {
  int v, k;
} sh[N];
inline void ckmin(int &a, int b) { a = ((a < b) ? a : b); }
inline void ckmax(int &a, int b) { a = ((a > b) ? a : b); }
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
void dfs(int x, int fa) {
  for (int u : e[x])
    if (u != fa) {
      dfs(u, x);
      for (int k = 0; k <= B; k++) dp[x][k] += max(1, dp[u][k] - k);
    }
}
void dfs1(int x, int fa) {
  memset(dp[x], 0, sizeof(dp[x]));
  sz[x] = 1;
  for (int u : e[x])
    if (u != fa) {
      dfs1(u, x);
      memset(f, 0, sizeof(f));
      int lim = min(B, sz[x]);
      for (int i = 0; i <= lim; i++) {
        ckmax(f[i], dp[x][i] + 1);
        int up = min(B, sz[u]);
        for (int j = 0; j <= up && i + j + 1 <= B; j++)
          ckmax(f[i + j + 1], dp[x][i] + dp[u][j]);
      }
      memcpy(dp[x], f, sizeof(f));
      sz[x] += sz[u];
    }
}
signed main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    e[u].push_back(v);
    e[v].push_back(u);
  }
  B = sqrt(n);
  dfs(1, 1);
  q = read();
  for (int i = 1; i <= q; i++) {
    sh[i] = (node){read(), read()};
    if (sh[i].k <= B) ans[i] = dp[sh[i].v][sh[i].k];
  }
  dfs1(1, 1);
  printf("OK\n");
  for (int i = 1; i <= q; i++)
    if (sh[i].k > B) {
      int MAX = 0;
      for (int j = 0; j <= B; j++) MAX = max(MAX, dp[sh[i].v][j] - j * sh[i].k);
      ans[i] = MAX;
    }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
}
