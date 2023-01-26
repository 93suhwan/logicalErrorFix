#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long INF = 0x3f3f3f3f;
long long pre[N], dp[N][500];
void solve() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    pre[i] = 0;
    scanf("%lld", &pre[i]);
    pre[i] = pre[i - 1] + pre[i];
  }
  int mx = 0;
  while (mx * (mx + 1) / 2 <= n) mx++;
  mx--;
  dp[n + 1][0] = INF;
  for (i = n; i >= 1; --i) {
    dp[i][0] = dp[i + 1][0];
    for (j = 1; j <= mx; ++j) {
      dp[i][j] = dp[i + 1][j];
      if (i + j - 1 <= n && pre[i + j - 1] - pre[i - 1] < dp[i + j][j - 1]) {
        dp[i][j] = max(dp[i][j], pre[i + j - 1] - pre[i - 1]);
      }
    }
  }
  for (i = mx; i >= 1; --i) {
    if (dp[1][i] > 0) {
      printf("%d\n", i);
      return;
    }
  }
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= mx; ++j) {
      dp[i][j] = 0;
    }
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
