#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long n = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = n * 10 + ch - '0';
    ch = getchar();
  }
  return n * f;
}
long long lcp[5005][5005];
char str[200005];
long long dp[5005];
signed main() {
  long long t, n, ans;
  t = read();
  for (long long greg = 1; greg <= t; greg++) {
    n = read();
    scanf("%s", str + 1);
    str[n + 1] = 0;
    for (long long i = n; i >= 1; i--) {
      for (long long j = n; j >= 1; j--) {
        if (str[i] != str[j])
          lcp[i][j] = 0;
        else if (i == n || j == n)
          lcp[i][j] = 1;
        else
          lcp[i][j] = lcp[i + 1][j + 1] + 1;
      }
    }
    for (long long i = 1; i <= n; i++) dp[i] = n - i + 1;
    for (long long i = 2; i <= n; i++) {
      for (long long j = 1; j <= i - 1; j++) {
        if (str[i + lcp[i][j]] > str[j + lcp[i][j]])
          dp[i] = max(dp[i], dp[j] + n - i + 1 - lcp[i][j]);
      }
    }
    ans = 0;
    for (long long i = 1; i <= n; i++) ans = max(ans, dp[i]);
    printf("%lld\n", ans);
  }
  return 0;
}
