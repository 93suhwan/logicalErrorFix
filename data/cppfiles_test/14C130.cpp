#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long power(long long a, long long b);
long long a[2002];
long long dp[2002][2002];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    long long n, k;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      for (long long j = 0; j <= n; j++) dp[i][j] = 0;
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = 0; j < i; j++) {
        long long curr = (i - j);
        dp[i][j] = dp[i - 1][j] + (curr == a[i]);
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      }
    }
    long long ans = -1;
    for (long long i = 0; i <= n; i++) {
      if (dp[n][i] >= k) {
        ans = i;
        break;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2)
      b--, res = res * a;
    else
      b = b / 2, a *= a;
  }
  return res;
}
