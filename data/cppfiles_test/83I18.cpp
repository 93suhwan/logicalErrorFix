#include <bits/stdc++.h>
using namespace std;
int read() {
  int w = 0, flg = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      flg = -1;
    }
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    w = w * 10 + ch - '0', ch = getchar();
  }
  return w * flg;
}
int T;
int n, del[5010][5010], dp[5010], ans;
char s[5010];
void solve() {
  for (int i = (1); i <= (n); i++) {
    dp[i] = 0;
    for (int j = (1); j <= (i - 1); j++) del[i][j] = 0;
  }
  n = read(), ans = 0;
  scanf("%s", s + 1);
  for (int i = (n); i >= (1); i--) {
    dp[i] = max(dp[i], n - i + 1);
    ans = max(ans, dp[i]);
    for (int j = (i - 1); j >= (1); j--) {
      if (s[i] > s[j]) {
        del[i][j] = n - j + 1;
        dp[j] = max(dp[j], dp[i] + del[i][j]);
      } else if (s[i] == s[j]) {
        del[i][j] = del[i + 1][j + 1];
        dp[j] = max(dp[j], dp[i] + del[i][j]);
      }
    }
  }
  printf("%d\n", ans);
}
int main() {
  T = read();
  while (T--) solve();
  return 0;
}
