#include <bits/stdc++.h>
int main() {
  using namespace std;
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, mod;
  cin >> n >> mod;
  vector<int> dp(n + 1), suf(n + 1);
  dp[n] = 1;
  for (int i = n - 1; i > 0; i--) {
    suf[i] = dp[i + 1] + suf[i + 1];
    if (suf[i] >= mod) suf[i] -= mod;
    dp[i] = suf[i];
    for (int j = 2; i * j <= n; j++) {
      int l = i * j, r = min(n + 1, l + j);
      int u = suf[l - 1] - suf[r - 1];
      if (u < 0) u += mod;
      dp[i] += u;
      if (dp[i] >= mod) dp[i] -= mod;
    }
  }
  cout << dp[1] << '\n';
  return 0;
}
