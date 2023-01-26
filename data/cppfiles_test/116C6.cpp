#include <bits/stdc++.h>
using namespace std;
int dadsadasda;
const int INF = 0x3f3f3f3f;
const long long INFLL = 1e18 + 1;
const int MOD = 998244353;
const int MAXN = 5e5 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long dp[2][MAXN];
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n + 2; j++) dp[i][j] = 0;
    for (int i = 0; i < n; i++) {
      long long temp = dp[0][a[i]];
      if (a[i]) temp = (temp + dp[0][a[i] - 1]) % MOD;
      long long temp2 = 0;
      if (a[i] >= 2) temp2 = dp[0][a[i] - 2];
      if (a[i] >= 1) temp2 = (temp2 + dp[1][a[i] - 1]) % MOD;
      long long temp3 = dp[1][a[i] + 1];
      dp[0][a[i]] = (dp[0][a[i]] + temp) % MOD;
      if (a[i] == 0) dp[0][a[i]] = (dp[0][a[i]] + 1) % MOD;
      if (a[i] >= 1) dp[1][a[i] - 1] = (dp[1][a[i] - 1] + temp2) % MOD;
      dp[1][a[i] + 1] = (dp[1][a[i] + 1] + temp3) % MOD;
      if (a[i] == 1) dp[1][0] = (dp[1][0] + 1) % MOD;
    }
    long long ans = 0;
    for (int i = 0; i < n + 2; i++) {
      ans = (ans + dp[0][i]) % MOD;
      ans = (ans + dp[1][i]) % MOD;
    }
    cout << ans << '\n';
  }
  return 0;
}
