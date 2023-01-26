#include <bits/stdc++.h>
using namespace std;
const int M = 205;
const int MOD = 1e9 + 7;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = 0;
  for (; c <= '9' && c >= '0'; c = getchar())
    x = (x << 1) + (x << 3) + (c ^ 48);
  return f ? x : -x;
}
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
int n, m, num[M][M], f[M][M];
vector<int> a;
struct edge {
  int v, nxt;
} ed[M << 1];
int head[M], cnt_edge;
inline void add_edge(int u, int v) {
  ed[++cnt_edge] = (edge){v, head[u]}, head[u] = cnt_edge;
}
inline void dfs(int x, int fa) {
  num[x][0] = 1;
  for (int i = head[x]; i; i = ed[i].nxt) {
    int v = ed[i].v;
    if (v != fa) {
      dfs(v, x);
      for (int j = 1; j <= n; j++) num[x][j] += num[v][j - 1];
    }
  }
}
int main() {
  int T = read();
  while (T--) {
    n = read(), m = read();
    int ans = 0;
    cnt_edge = 0;
    for (int i = 0; i <= n; i++) head[i] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= n; j++) num[i][j] = 0;
    }
    for (int i = 1; i < n; i++) {
      int u = read(), v = read();
      add_edge(u, v), add_edge(v, u);
    }
    if (m == 2) {
      printf("%d\n", n * (n - 1) / 2);
      continue;
    }
    for (int i = 1; i <= n; i++) {
      dfs(i, 0);
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= a.size(); k++) {
          for (int l = 1; l <= k; l++) f[k][l] = 0;
        }
        a.clear();
        for (int l = head[i]; l; l = ed[l].nxt)
          a.push_back(num[ed[l].v][j - 1]);
        f[0][0] = 1;
        for (int k = 1; k <= a.size(); k++) {
          f[k][0] = 1;
          for (int l = 1; l <= k; l++)
            f[k][l] = (f[k - 1][l] + f[k - 1][l - 1] * a[k - 1] % MOD) % MOD;
        }
        ans = (ans + f[a.size()][m]) % MOD;
      }
      for (int j = 1; j <= n; j++) {
        for (int l = 0; l <= n; l++) num[j][l] = 0;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
