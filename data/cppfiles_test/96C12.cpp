#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const long long MOD = 998244353;
long long comb[MAXN][MAXN];
long long pot[MAXN][MAXN];
long long fpow(long long b, long long e) {
  long long res = 1;
  while (e) {
    if (e & 1) res = res * b % MOD;
    b = b * b % MOD, e >>= 1;
  }
  return res;
}
long long dp[MAXN][MAXN];
long long f(long long x, long long y) {
  long long &res = dp[x][y];
  if (res >= 0) return res;
  if (x == 0 || y == 0) return res = 0;
  if (x == 1) return res = y;
  res = 0;
  for (int i = 0, ggdem = x; i < ggdem; ++i) {
    long long val = comb[x][i] * pot[min(y, x - 1)][i] % MOD;
    res = (res + val * f(x - i, y - min(y, x - 1))) % MOD;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, x;
  cin >> n >> x;
  for (int i = 0, ggdem = MAXN; i < ggdem; ++i) {
    for (int j = 0, ggdem = i + 1; j < ggdem; ++j) {
      if (j == 0 || j == i)
        comb[i][j] = 1;
      else
        comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
    }
  }
  for (int i = 0, ggdem = MAXN; i < ggdem; ++i) {
    for (int j = 0, ggdem = MAXN; j < ggdem; ++j) {
      pot[i][j] = fpow(i, j);
    }
  }
  memset((dp), (-1), sizeof(dp));
  long long res = (pot[x][n] + MOD - f(n, x)) % MOD;
  cout << res << "\n";
  return 0;
}
