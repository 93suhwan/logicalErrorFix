#include <bits/stdc++.h>
using namespace std;
int md = 1000000007;
int a, b, n;
long long fastpow(long long x, long long n) {
  long long ret = 1;
  while (x) {
    if (x & 1) (ret *= n) %= md;
    x >>= 1;
    (n *= n) %= md;
  }
  return ret;
}
bool cf(int x) {
  int f = 1;
  while (x) {
    int r = x % 10;
    if (r == a or r == b)
      ;
    else
      f = 0;
    x /= 10;
  }
  return f;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long df[n];
    for (auto &i : df) cin >> i;
    sort(df, df + n);
    long long dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) dp[i] = df[i - 1], dp[i] += dp[i - 1];
    double ans = -1e18;
    for (int i = 1; i <= n; ++i) {
      int x = i, y = n - i;
      double a = dp[i], b = dp[n] - dp[i];
      double sa = (double)a, sb = (double)b;
      sa /= (double)x;
      sb /= (double)y;
      double tans = sa + sb;
      ans = max(ans, tans);
    }
    cout << setprecision(12) << ans << '\n';
  }
}
