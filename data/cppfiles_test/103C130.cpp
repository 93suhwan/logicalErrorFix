#include <bits/stdc++.h>
using namespace std;
int n, m, d[4000005];
int f[4000005], dp[4000005];
int g[4000005];
queue<int> q;
int mx, h;
void dfs(int u) {
  if (!d[u]) return;
  d[u] = 0;
  h++;
  if (dp[u] >= dp[mx]) mx = u;
  dfs(g[u]);
}
void init() {
  for (int i = 1; i <= n * m; i++) {
    d[i] = g[i] = f[i] = dp[i] = 0;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char ch = getchar();
        while (ch != 'L' && ch != 'R' && ch != 'D' && ch != 'U') ch = getchar();
        if (ch == 'L' && j > 1)
          g[((i - 1) * m + j)] = ((i - 1) * m + j - 1),
                           d[((i - 1) * m + j - 1)]++;
        if (ch == 'R' && j < m)
          g[((i - 1) * m + j)] = ((i - 1) * m + j + 1),
                           d[((i - 1) * m + j + 1)]++;
        if (ch == 'U' && i > 1)
          g[((i - 1) * m + j)] = ((i - 1 - 1) * m + j),
                           d[((i - 1 - 1) * m + j)]++;
        if (ch == 'D' && i < n)
          g[((i - 1) * m + j)] = ((i + 1 - 1) * m + j),
                           d[((i + 1 - 1) * m + j)]++;
      }
    }
    for (int i = 1; i <= n * m; i++) {
      if (d[i] == 0) {
        f[i] = i;
        dp[i] = 1;
        q.push(i);
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      int v = g[u];
      if (v == 0) continue;
      if (dp[u] + 1 > dp[v]) {
        f[v] = f[u];
        dp[v] = dp[u] + 1;
      }
      d[v]--;
      if (d[v] == 0) {
        q.push(v);
      }
    }
    for (int i = 1; i <= n * m; i++) {
      if (d[i]) {
        h = 0, mx = 0;
        dfs(i);
        if (dp[mx] == 0) {
          f[mx] = mx;
          dp[mx] += h;
        } else {
          dp[mx] += h - 1;
        }
      }
    }
    int id = 0;
    for (int i = 1; i <= n * m; i++) {
      if (dp[i] > dp[id]) id = i;
    }
    printf("%d %d %d\n", (f[id] - 1) / m + 1, (f[id] - 1) % m + 1, dp[id]);
  }
  return 0;
}
