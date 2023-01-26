#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long inf = 1e10;
const int SIZE = 4e5;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
inline long long _ceil(long long a, long long b) { return (a + b - 1) / b; }
inline long long _min(long long a, long long b) { return a > b ? b : a; };
inline long long _max(long long a, long long b) { return a > b ? a : b; };
int solve() {
  int n;
  cin >> n;
  long long x[n], y[n];
  int s[n];
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> s[i];
  long long dp[n + 1], sum[n + 1];
  dp[0] = 0;
  sum[0] = 0;
  for (int i = 0; i < n; i++) {
    long long val = y[i];
    int l = 0, r = i;
    while (l <= r) {
      int m = (l + r) / 2;
      if (x[m] < val)
        l = m + 1;
      else
        r = m - 1;
    }
    dp[i + 1] = (MOD2 + ((sum[i] - sum[l]) + (x[i] - y[i])) % MOD2) % MOD2;
    sum[i + 1] = (sum[i] + dp[i + 1]) % MOD2;
  }
  long long ans = x[n - 1] + 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 1) ans = (ans + dp[i + 1]) % MOD2;
  }
  cout << ans << "\n";
}
int main() {
  int t = 1;
  while (t--) solve();
}
