#include <bits/stdc++.h>
using namespace std;
const long long MD = 1e9 + 7;
const long long Inf = 2e16;
const long long SQ = 500;
const long long N = 1e5 + 5;
long long arr[N], ps[N], dp[N][SQ];
long long sqr(long long n) {
  long long l = 0, r = 1e9 + 1;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    if (mid * mid <= n)
      l = mid;
    else
      r = mid;
  }
  return l;
}
void Main() {
  long long n;
  cin >> n;
  long long sq = 2 * sqr(n) + 5;
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  ps[0] = 0;
  for (long long i = 1; i <= n; i++) ps[i] = arr[i] + ps[i - 1];
  for (long long i = 0; i <= n + 4; i++)
    for (long long j = 0; j <= sq + 4; j++) dp[i][j] = -Inf;
  dp[n][1] = arr[n];
  for (long long i = n - 1; i >= 1; i--) dp[i][1] = max(arr[i], dp[i + 1][1]);
  for (long long k = 2; k <= sq - 1; k++)
    for (long long i = n; i >= 1; i--)
      if ((1LL * i + 1LL * (k * (k + 1) / 2) - 1) <= n) {
        if ((ps[i + k - 1] - ps[i - 1]) < dp[i + k][k - 1]) {
          dp[i][k] = ps[i + k - 1] - ps[i - 1];
        }
        if ((i + (k * (k + 1) / 2) - 1) != n) {
          dp[i][k] = max(dp[i][k], dp[i + 1][k]);
        }
      }
  long long ans = 0;
  for (long long i = 1; i <= sq - 1; i++)
    if (dp[1][i] >= 0) ans = i;
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
