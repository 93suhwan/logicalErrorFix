#include <bits/stdc++.h>
using namespace std;
long long n;
const long long maxn = 1e4 + 3, maxDiff = 2e3 + 1;
long long a[maxn];
const long long inf = 1e9 + 7;
long long dp[maxn][maxDiff];
long long amax;
void getInput() {
  cin >> n;
  for (long long i = (0); i < (n); i++) cin >> a[i];
}
void clearUp() {
  for (long long i = (0); i <= (n); i++)
    for (long long j = (0); j <= (2 * amax); j++) dp[i][j] = -1;
}
void setValue(long long i, long long j, long long val) {
  if (dp[i][j] == -1)
    dp[i][j] = val;
  else
    dp[i][j] = min(dp[i][j], val);
}
long long solve() {
  getInput();
  amax = 0;
  for (long long i = (1); i <= (n); i++) amax = max(amax, a[i]);
  clearUp();
  dp[0][0] = 0;
  for (long long i = (0); i <= (n - 1); i++)
    for (long long j = (0); j <= (2 * amax); j++) {
      if (dp[i][j] != -1) {
        setValue(i + 1, max(0LL, j - a[i]), dp[i][j] + a[i]);
        if (j + a[i] <= 2 * amax)
          setValue(i + 1, j + a[i], max(0LL, dp[i][j] - a[i]));
      }
    }
  long long ans = inf;
  for (long long j = (0); j <= (2 * amax); j++)
    if (dp[n][j] != -1) ans = min(ans, j + dp[n][j]);
  return ans;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long T;
  cin >> T;
  while (T--) {
    cout << solve() << '\n';
  }
  return 0;
}
