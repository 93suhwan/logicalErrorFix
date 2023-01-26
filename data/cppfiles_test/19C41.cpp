#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 1000000007;
const double pi = 3.1415926535897932, eps = 1e-6;
void chmax(int &x, int y) {
  if (x < y) x = y;
}
void chmin(int &x, int y) {
  if (x > y) x = y;
}
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = (long long)ret * x % mod;
    x = (long long)x * x % mod;
    y >>= 1;
  }
  return ret;
}
int T, n, a[10005], dp[10005][2005];
void solve() {
  scanf("%d", &n);
  for (int(i) = (1); (i) <= (n); (i)++) scanf("%d", a + i);
  for (int(i) = (0); (i) <= (n); (i)++)
    for (int(j) = (0); (j) <= (2000); (j)++) dp[i][j] = inf;
  dp[0][0] = 0;
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) <= (2000); (j)++) {
      int v = dp[i][j];
      if (j < a[i + 1]) {
        chmin(dp[i + 1][0], v + a[i + 1] - j);
      } else
        chmin(dp[i + 1][j - a[i + 1]], v);
      if (j + a[i + 1] <= 2000) {
        if (j + a[i + 1] > v) {
          chmin(dp[i + 1][j + a[i + 1]], j + a[i + 1]);
        } else
          chmin(dp[i + 1][j + a[i + 1]], v);
      }
    }
  int ans = inf;
  for (int(i) = (0); (i) <= (2000); (i)++) ans = min(ans, dp[n][i]);
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
