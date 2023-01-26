#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
int test = 1;
int n, mod1;
unsigned long dp[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  cin >> n >> mod1;
  memset(dp, 0, sizeof(dp));
  dp[2] = 2;
  dp[1] = 1;
  dp[0] = 0;
  for (int i = 3; i <= n; i++) {
    dp[i] = (2 * dp[i - 1] + 1) % mod1;
    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        dp[i] = (dp[i] + dp[i / j] + mod1 - dp[(i / j) - 1]) % mod1;
        if (i / j != j) dp[i] = (dp[i] + dp[j] + mod1 - dp[j - 1]) % mod1;
      }
    }
  }
  cout << dp[n] % mod1 << endl;
}
