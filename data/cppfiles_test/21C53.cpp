#include <bits/stdc++.h>
const int N = 102;
int n, m, k, p, c[N][N], f[N], dp[N][N][N];
int add(int a, int b) { return a + b < p ? a + b : a + b - p; }
int init(int x, int y, int z) {
  if (dp[x][y][z] != -1) return dp[x][y][z];
  if (x < y) return dp[x][y][z] = 0;
  if (x < z) return dp[x][y][z] = (y ? 0 : f[x]);
  if (!z) {
    dp[x][y][z] = (!y ? f[x] : 0);
    return dp[x][y][z];
  } else if (!x) {
    dp[x][y][z] = (!y ? 1 : 0);
    return dp[x][y][z];
  }
  if (y > x - z + 1) return dp[x][y][z] = 0;
  return dp[x][y][z];
}
int DP(int x, int y, int z) {
  if (dp[x][y][z] != -1) return dp[x][y][z];
  init(x, y, z);
  int ans = 0;
  for (int i = 1; i <= x; ++i) {
    int s = 0;
    int r = y - (z == 1 ? 1 : 0);
    int r2 = std::min(r, i - z + 1);
    for (int j = 0; j <= r; ++j) {
      int a = init(i - 1, j, z - 1);
      int b = init(x - i, r - j, z - 1);
      if (!a || !b) continue;
      s = add(s, 1ll * DP(i - 1, j, z - 1) * DP(x - i, r - j, z - 1) % p);
    }
    ans = add(ans, 1ll * s * c[x - 1][i - 1] % p);
  }
  dp[x][y][z] = ans;
  return dp[x][y][z];
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &p);
  f[0] = 1;
  c[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    c[i][0] = c[i][i] = 1;
    f[i] = 1ll * f[i - 1] * i % p;
    for (int j = 1; j < i; ++j) {
      c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
    }
  }
  memset(dp, -1, sizeof(dp));
  printf("%d\n", DP(n, k, m));
  return 0;
}
