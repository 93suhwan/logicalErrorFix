#include <bits/stdc++.h>
using namespace std;
int dp[2010][2010], a[2010];
template <typename _T>
void rd(_T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9')
    x = (x << 3) + (x << 1) + (s - '0'), s = getchar();
  x *= f;
}
int main() {
  int _;
  for (rd(_); _; _--) {
    int n, k;
    rd(n), rd(k);
    for (int i = 1; i <= n; i++) rd(a[i]);
    int ans = 2092371547;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        dp[i][j] = max(dp[i - 1][j - 1] + (a[i] == j), dp[i - 1][j]);
        if (dp[i][j] >= k) ans = min(ans, i - j);
      }
    }
    printf("%d\n", (ans == 2092371547) ? -1 : ans);
  }
  return 0;
}
