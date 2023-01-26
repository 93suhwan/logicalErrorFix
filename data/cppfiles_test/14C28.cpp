#include <bits/stdc++.h>
using namespace std;
int a[2005], b[2005];
int dp[2005];
void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[i] = i - a[i];
  }
  memset(dp, 0, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i] < 0) continue;
    for (int j = 0; j < i; j++) {
      if (b[j] < 0) continue;
      if (b[i] - b[j] >= 0 && b[i] - b[j] < i - j)
        dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    if (dp[i] >= k) ans = min(ans, b[i]);
  }
  if (ans == 1e9)
    printf("-1\n");
  else
    printf("%d\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
