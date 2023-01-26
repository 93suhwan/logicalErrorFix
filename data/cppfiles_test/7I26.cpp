#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[505], t[505];
int dp[505][505][505];
int to[505];
int calc(string c) {
  int len = c.size() - 1;
  int ans = 0;
  for (int l = 1; l <= min(len, m); l++) {
    int i = 1, j = len - l + 1;
    bool flag = 0;
    while (i <= l) {
      if (t[i] != c[j]) {
        flag = 1;
        break;
      }
      i++;
      j++;
    }
    if (!flag) ans = l;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  string tmp = "";
  to[0] = 0;
  for (int i = 1; i <= m; i++) {
    int k = t[i % m + 1] - '0';
    k ^= 1;
    tmp += t[i];
    string ttmp = tmp + (char)('0' + k);
    to[i] = calc(ttmp);
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k <= n - m + 1; k++) {
        if (dp[i][j][k] == 0x3f3f3f3f) continue;
        int op = 0;
        if (s[i + 1] != t[j + 1]) op = 1;
        if (j == m - 1) {
          dp[i + 1][j + 1][k + 1] =
              min(dp[i + 1][j + 1][k + 1], dp[i][j][k] + op);
          dp[i + 1][to[j]][k] =
              min(dp[i + 1][to[j]][k], dp[i][j][k] + (op ^ 1));
        } else {
          dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], dp[i][j][k] + op);
          dp[i + 1][to[j]][k] =
              min(dp[i + 1][to[j]][k], dp[i][j][k] + (op ^ 1));
        }
      }
      int op = 0;
      if (s[i + 1] != t[1]) op = 1;
      for (int k = 0; k <= n - m + 1; k++) {
        if (dp[i][m][k] == 0x3f3f3f3f) continue;
        dp[i + 1][1][k] = min(dp[i + 1][1][k], dp[i][m][k] + op);
        dp[i + 1][to[m]][k] = min(dp[i + 1][to[m]][k], dp[i][m][k] + (op ^ 1));
      }
    }
  }
  for (int i = 0; i <= n - m + 1; i++) {
    int ans = 0x3f3f3f3f;
    for (int j = 0; j <= m; j++) ans = min(ans, dp[n][j][i]);
    if (ans != 0x3f3f3f3f)
      printf("%d ", ans);
    else
      printf("-1 ");
  }
  return 0;
}
