#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long sum[N], a[N], dp[N][500];
void solve() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  int mx = 1;
  while (mx * (mx - 1) / 2 < n) mx++;
  dp[n][1] = a[n];
  for (i = n - 1; i >= 1; --i) {
    for (j = 1; j <= mx; ++j) {
      dp[i][j] = dp[i + 1][j];
      if (i + j - 1 <= n && sum[i + j - 1] - sum[i - 1] < dp[i + j][j - 1]) {
        dp[i][j] = max(dp[i][j], sum[i + j - 1] - sum[i - 1]);
      }
    }
  }
  for (i = mx; i >= 1; --i) {
    if (dp[1][i] > 0) {
      printf("%d\n", i);
      break;
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
