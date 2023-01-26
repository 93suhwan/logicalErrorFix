#include <bits/stdc++.h>
using namespace std;
long long fastxp(long long n, long long e) {
  long long ans = 1, pwr = n;
  while (e) {
    if (e % 2) ans = ans * pwr % 1000000007;
    e /= 2;
    pwr = pwr * pwr % 1000000007;
  }
  return ans;
}
long long n;
long long a[20], win[20][20], dp[1 << 14];
long long win_all(long long m1, long long m2) {
  long long ret = 1;
  for (long long i = 0; i < n; i++)
    if ((1 << i) & m1)
      for (long long j = 0; j < n; j++)
        if ((1 << j) & m2) {
          ret = ret * win[i][j] % 1000000007;
        }
  return ret;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++)
      win[i][j] = a[i] * fastxp(a[i] + a[j], 1000000007 - 2) % 1000000007;
  long long ans = 0;
  for (long long mask = 0; mask < (1 << n); mask++) {
    dp[mask] = 1;
    for (long long i = mask & (mask - 1); i > 0; i = (i - 1) & mask) {
      dp[mask] = (dp[mask] - win_all(i, mask ^ i) * dp[i]) % 1000000007;
    }
    dp[mask] = (dp[mask] + 1000000007) % 1000000007;
    ans = (__builtin_popcount(mask) * dp[mask] % 1000000007 *
               win_all(mask, ((1 << n) - 1) ^ mask) +
           ans) %
          1000000007;
  }
  cout << ans << endl;
}
