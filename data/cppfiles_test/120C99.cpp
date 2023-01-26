#include <bits/stdc++.h>
using namespace std;
long long dp[31][200005];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (long long i = 0; i <= 30; i++)
    for (long long j = 1; j <= 200000; j++)
      dp[i][j] = dp[i][j - 1] + !(j & (1 << i));
  long long T;
  cin >> T;
  while (T--) {
    long long l, r;
    cin >> l >> r;
    long long ans = 0x7fffffff;
    for (long long i = 0; (1 << i) <= r; i++) {
      ans = min(ans, (dp[i][r] - dp[i][l - 1]));
    }
    cout << ans << '\n';
  }
  return 0;
}
