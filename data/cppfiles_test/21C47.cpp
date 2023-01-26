#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2,sse3")
using namespace std;
inline int read() {
  char ch = getchar();
  int w = 1, c = 0;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') w = -1;
  for (; isdigit(ch); ch = getchar()) c = (c << 1) + (c << 3) + (ch ^ 48);
  return w * c;
}
const int M = 111;
int n, m, k, mod;
bool vis[M][M][M];
int dp[M][M][M];
int C[M][M];
long long fac[M];
void init() {
  for (int i = (0); i <= (n); ++i) {
    C[i][0] = 1;
    for (int j = (1); j <= (i); ++j) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
  fac[0] = 1;
  for (int i = (1); i <= (n); ++i) fac[i] = fac[i - 1] * i % mod;
}
int dfs(int le, int x, int y) {
  if (!le) return (!y);
  if (le == 1) {
    if (x == 1 && y == 1) return 1;
    if (x != 1 && !y) return 1;
    return 0;
  }
  if (x == 1) {
    if (y == 1) return fac[le];
    return 0;
  }
  if (y > le) return 0;
  if (x > le) {
    if (!y)
      return fac[le];
    else
      return 0;
  }
  if (vis[le][x][y]) return dp[le][x][y];
  long long ret = 0;
  vis[le][x][y] = 1;
  for (int i = (0); i <= (le - 1); ++i) {
    for (int l = (max(0, y - le + i + 1)); l <= (min(y, i)); ++l) {
      ret = (ret + 1ll * dfs(i, x - 1, l) * dfs(le - 1 - i, x - 1, y - l) %
                       mod * C[le - 1][i]) %
            mod;
    }
  }
  return dp[le][x][y] = ret;
}
int main() {
  n = read();
  m = read();
  k = read();
  mod = read();
  init();
  cout << dfs(n, m, k) % mod << "\n";
  return 0;
}
