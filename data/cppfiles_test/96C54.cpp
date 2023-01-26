#include <bits/stdc++.h>
using namespace std;
long long int fac[505];
long long int power[505][505];
long long int NCR[505][505];
void init() {
  fac[0] = 1;
  for (long long int i = 1; i < 505; i++) fac[i] = (fac[i - 1] * i) % 998244353;
  for (long long int i = 1; i < 505; i++) {
    power[i][0] = 1;
    for (long long int j = 1; j < 505; j++)
      power[i][j] = (power[i][j - 1] * i) % 998244353;
  }
  for (long long int i = 0; i < 505; i++) NCR[i][0] = 1;
  for (long long int i = 1; i < 505; i++) {
    for (long long int j = 1; j <= i; j++) {
      NCR[i][j] = (NCR[i - 1][j - 1] + NCR[i - 1][j]) % 998244353;
    }
  }
}
void solve() {
  long long int n, x;
  cin >> n >> x;
  long long int dp[n + 1][x + 1];
  for (long long int j = 0; j <= x; j++) dp[0][j] = 1;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 0; j <= x; j++) {
      dp[i][j] = 0;
      if (j >= (i - 1)) {
        for (long long int k = 0; k <= i; k++) {
          if (k == i - 1) continue;
          long long int cnt = (NCR[i][k] * power[i - 1][k]) % 998244353;
          cnt *= dp[i - k][j - (i - 1)];
          cnt %= 998244353;
          dp[i][j] += cnt;
          dp[i][j] %= 998244353;
        }
      } else {
        dp[i][j] = power[j][i];
      }
    }
  }
  cout << dp[n][x];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  long long int t = 1;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
