#include <bits/stdc++.h>
using namespace std;
const long long N = 32;
long long timer, cc1, cc;
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % 998244353;
  while (y > 0) {
    if (y & 1LL) {
      res = res * x;
      res = res % 998244353;
    }
    y = y >> 1LL;
    x = x * x;
    x = x % 998244353;
  }
  return res;
}
long long dp[500005];
int main() {
  boost();
  long long i, t, q, l, r, ans, mid, c = 0, j, z, tc, n, k;
  long long h, m, u, mm, w, x, y, l1, r1, d = 0, mask, v, mx;
  long double f, f1;
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 0;
    iota(dp, dp + n + 1, 0);
    for (i = 0; i < n; i++) {
      cin >> l;
      z = dp[l];
      dp[l] += z;
      dp[l] %= 998244353;
      ans += z;
      ans %= 998244353;
      if (l == 0) {
        dp[l]++;
        dp[l] %= 998244353;
        ans++;
      }
      ans %= 998244353;
    }
    cout << ans << '\n';
  }
  return 0;
}
