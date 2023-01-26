#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 5;
int dp[maxn];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, mod;
  cin >> n >> mod;
  dp[1] = 1;
  int now = 0;
  for (int i = 2; i <= n; ++i) {
    now = dp[i] = (1LL * dp[i] + now + dp[i - 1] + 1) % mod;
    for (int j = 2 * i; j <= n; j += i) {
      dp[j] = (1LL * dp[j] + dp[i] - dp[i - 1]) % mod;
    }
  }
  cout << dp[n];
  return 0;
}
