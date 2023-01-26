#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
const int N = 107;
int mod;
int fac[N], C[N][N];
int dp[N][N][N];
int DP(int x, int y, int z) {
  if (x == 0) return z == 0;
  if (y == 1) return z == 1 ? fac[x] : 0;
  if (z && y + z - 2 > x) return 0;
  if (dp[x][y][z] != -1) return dp[x][y][z];
  int ret = 0;
  for (int i = (1); i <= (x); ++i) {
    for (int a = (0); a <= (z); ++a) {
      (ret += (long long)C[x - 1][i - 1] * DP(i - 1, y - 1, a) % mod *
              DP(x - i, y - 1, z - a) % mod) %= mod;
    }
  }
  return dp[x][y][z] = ret;
}
int n, m, k;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  n = 100, m = 29, k = 51, mod = 667663580;
  if (mod == 1) return cout << 0 << "\n", 0;
  for (int i = (0); i <= (n); ++i) C[i][0] = 1;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (i); ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  fac[0] = 1;
  for (int i = (1); i <= (n); ++i) fac[i] = (long long)fac[i - 1] * i % mod;
  memset(dp, -1, sizeof(dp));
  cout << DP(n, m, k) << "\n";
  return 0;
}
