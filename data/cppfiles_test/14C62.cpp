#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
int a[maxn], dp[maxn][maxn];
void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) dp[i][j] = 0;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = dp[i - 1][j] + (a[i] + j == i);
      if (j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
    }
  }
  int ans = -1;
  for (int i = 0; i <= n; i++) {
    if (dp[n][i] >= k) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
