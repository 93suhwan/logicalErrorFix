#include <bits/stdc++.h>
using namespace std;
string a[64];
long long dp[64];
void solve(long long test) {
  long long n, k, c = 0, ans = INT_MAX, x = 0, y = 0;
  cin >> n;
  string s = to_string(n);
  for (long long i = 0; i <= 63; i++) {
    long long j = 0, k = 0;
    x = 0;
    while (j < a[i].length() && k < s.length()) {
      if (a[i][j] == s[k]) {
        j++;
        k++;
      } else {
        k++;
        x++;
      }
    }
    if (s.length() > k) x += (s.length() - k);
    if (a[i].length() > j) x += (a[i].length() - j);
    ans = min(ans, x);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  dp[0] = 1;
  a[0] = to_string(dp[0]);
  for (long long i = 1; i <= 63; i++) {
    dp[i] = dp[i - 1] * 2;
    a[i] = to_string(dp[i]);
  }
  long long t;
  cin >> t;
  for (long long z1 = 1; z1 <= t; z1++) {
    solve(z1);
  };
}
