#include <bits/stdc++.h>
using namespace std;
long long i, j, p, q, n, m, k, dp[4000006], sum, g, dpp[4000006];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  dp[1] = 1;
  sum = 1;
  for (i = 2; i <= n; i++) dpp[i] += 1;
  dp[2] = 2;
  dpp[2] = 1;
  for (i = 4; i <= n; i += 2) dpp[i]++;
  sum = 3;
  for (i = 3; i <= n; i++) {
    dp[i] = sum;
    dp[i] %= m;
    dpp[i] += dpp[i - 1];
    dpp[i] %= m;
    dp[i] = dpp[i] + dp[i];
    dp[i] %= m;
    for (j = i * 2; j <= n; j += i) {
      dpp[j] += dp[i] - dp[i - 1];
      if (dpp[j] < 0) dpp[j] += m;
      dpp[j] %= m;
    }
    sum += dp[i];
    sum %= m;
  }
  cout << dp[n] << '\n';
  return 0;
}
