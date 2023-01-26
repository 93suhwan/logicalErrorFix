#include <bits/stdc++.h>
const long long N = 205, P = 1000000007;
long long T, n, k, x, y, num[N][N], f[N][N];
std::vector<long long> g[N];
std::vector<long long> a;
void dfs(long long u, long long fa) {
  num[u][0] = 1;
  for (long long i = 0; i < (long long)g[u].size(); i++) {
    long long v = g[u][i];
    if (v == fa) continue;
    dfs(v, u);
    for (long long j = 1; j <= n; j++) num[u][j] += num[v][j - 1];
  }
}
signed main() {
  std::cin >> T;
  while (T--) {
    std::cin >> n >> k;
    long long ans = 0;
    for (long long i = 1; i < n; i++)
      std::cin >> x >> y, g[x].push_back(y), g[y].push_back(x);
    if (k == 2) {
      std::cout << n * (n - 1) / 2 << '\n';
      for (long long i = 1; i <= n; i++) g[i].clear();
      continue;
    }
    for (long long i = 1; i <= n; i++) {
      dfs(i, 0);
      for (long long j = 1; j <= n; j++) {
        for (long long l = 0; l < (long long)g[i].size(); l++)
          a.push_back(num[g[i][l]][j - 1]);
        f[0][0] = 1;
        for (long long x = 1; x <= (long long)a.size(); x++) {
          f[x][0] = 1;
          for (long long y = 1; y <= x; y++)
            f[x][y] = (f[x - 1][y] + f[x - 1][y - 1] * a[x - 1] % P) % P;
        }
        ans = (ans + f[a.size()][k]) % P;
        for (long long x = 1; x <= (long long)a.size(); x++)
          for (long long y = 1; y <= x; y++) f[x][y] = 0;
        a.clear();
      }
      for (long long j = 1; j <= n; j++)
        for (long long l = 0; l <= n; l++) num[j][l] = 0;
    }
    std::cout << ans << '\n';
    for (long long i = 1; i <= n; i++) g[i].clear();
    for (long long i = 1; i <= n; i++)
      for (long long j = 0; j <= n; j++) num[i][j] = 0;
  }
  return 0;
}
