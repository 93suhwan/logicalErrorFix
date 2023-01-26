#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int INF = 1 << 30;
const double eps = 1e-6;
const long long mod = 998244353;
long long dp[maxn][2][2];
int main() {
  int n;
  cin >> n;
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = dp[0][0][1] = 1;
  dp[0][1][0] = dp[0][1][1] = 1;
  string s;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    if (s[0] == '?' || s[0] == 'W') {
      dp[i][0][0] = dp[i - 1][1][1];
    } else
      dp[i][0][0] = 0;
    if (s[0] == '?' || s[0] == 'B') {
      dp[i][0][1] = dp[i - 1][1][0];
    } else
      dp[i][0][1] = 0;
    long long sum = (dp[i][0][0] + dp[i][0][1]) % mod;
    if (s[1] == '?' || s[1] == 'W') {
      dp[i][1][0] = sum;
    } else
      dp[i][1][0] = 0;
    if (s[1] == '?' || s[1] == 'B') {
      dp[i][1][1] = sum;
    } else
      dp[i][1][1] = 0;
  }
  if (s[1] == '?' || s[1] == 'W') {
    dp[1][0][0] = (dp[1][0][0] * dp[n][1][1]) % mod;
  } else
    dp[1][0][0] = 0;
  if (s[1] == '?' || s[1] == 'B') {
    dp[1][0][1] = (dp[1][0][1] * dp[n][1][0]) % mod;
  } else
    dp[1][0][0] = 0;
  long long ans = 0;
  for (int i = 0; i < 2; i++) ans = (ans + dp[1][0][i]) % mod;
  cout << ans << endl;
  return 0;
}
