#include <bits/stdc++.h>
using namespace std;
long long dp[61][6];
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  for (long long i = 0; i < 6; i++) {
    dp[0][i] = 1;
  }
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j < 6; j++) {
      for (long long l = 0; l < 6; l++) {
        for (long long m = 0; m < 6; m++) {
          if (j == l or j == m) {
            continue;
          }
          if ((j ^ 1) == l or (j ^ 1) == m) {
            continue;
          }
          dp[i][j] = (dp[i][j] + dp[i - 1][l] * dp[i - 1][m]) % mod;
        }
      }
    }
  }
  long long ans = 6 * (dp[n - 1][0]) % mod;
  cout << ans << '\n';
  return 0;
}
