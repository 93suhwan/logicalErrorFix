#include <bits/stdc++.h>
using namespace std;
int yh() {
  int ret = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == EOF) return -1;
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) ret = (ret << 3) + (ret << 1) + (c ^ 48), c = getchar();
  return f ? -ret : ret;
}
const int maxn = 2005;
int dp[maxn][maxn];
int n, k, a[maxn];
int main() {
  for (int _ = (yh()), _ss = (1); _ >= _ss; _--) {
    n = yh(), k = yh();
    for (int i = (0), iss = (n); i <= iss; i++)
      for (int j = (0), jss = (k); j <= jss; j++) dp[i][j] = 0;
    for (int i = (1), iss = (n); i <= iss; i++) {
      a[i] = yh();
      for (int j = (1), jss = (i); j <= jss; j++) {
        dp[i][j] = max(dp[i - 1][j - 1] + (j == a[i]), dp[i - 1][j]);
      }
    }
    int ans = 0x3f3f3f3f;
    for (int i = (0), iss = (n); i <= iss; i++)
      for (int j = (0), jss = (n); j <= jss; j++) {
        if (dp[i][j] == k) ans = min(ans, i - j);
      }
    if (ans != 0x3f3f3f3f)
      cout << ans << '\n';
    else
      puts("-1");
  }
  return 0;
}
