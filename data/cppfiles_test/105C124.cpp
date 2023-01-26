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
const int maxn = 3e3 + 5;
int dp[maxn][maxn];
int a[maxn];
int pre[maxn], nxt[maxn], last[maxn];
int n;
int main() {
  for (int _ = (yh()), _ss = (1); _ >= _ss; _--) {
    n = yh();
    for (int i = (1), iss = (n); i <= iss; i++) {
      pre[i] = 0, nxt[i] = n + 1, a[i] = yh(), last[i] = n + 1;
    }
    for (int i = (n), iss = (1); i >= iss; i--) {
      nxt[i] = last[a[i]];
      last[a[i]] = i;
    }
    for (int i = (1), iss = (n); i <= iss; i++) last[i] = 0;
    for (int i = (1), iss = (n); i <= iss; i++) {
      pre[i] = last[a[i]];
      last[a[i]] = i;
    }
    for (int i = (1), iss = (n); i <= iss; i++) dp[i][i] = 0;
    for (int i = (1), iss = (n - 1); i <= iss; i++)
      dp[i][i + 1] = (a[i] != a[i + 1]);
    for (int l = (3), lss = (n); l <= lss; l++) {
      for (int i = (1), iss = (n - l + 1); i <= iss; i++) {
        int j = i + l - 1;
        dp[i][j] = min(j - i, dp[i + 1][j] + (a[i] != a[i + 1]));
        for (int k = nxt[i]; k <= j; k = nxt[k]) {
          dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + 1 + dp[k][j]);
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
        for (int k = pre[j]; k >= i; k = pre[k]) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1] + 1);
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
    cout << dp[1][n] << '\n';
  }
  return 0;
}
