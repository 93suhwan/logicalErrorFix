#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n + 1), dp(n + 1, -1e18);
  map<long long, long long> mp;
  dp[0] = 0;
  for (long long i = 0; i < n; i++) {
    cin >> v[i + 1];
    v[i + 1] -= (i + 1);
    v[i + 1] = -v[i + 1];
  }
  for (long long i = 1; i <= n; i++) {
    long long res = -1e18;
    for (long long j = 0; j < i; j++) {
      if (v[j] >= 0 && v[i] - v[j] <= i - j - 1 && v[i] >= v[j]) {
        res = max(res, dp[j] + 1);
      }
    }
    dp[i] = res;
  }
  long long ans = 1e18;
  for (long long i = 0; i <= n; i++) {
    if (dp[i] >= k) {
      ans = min(ans, v[i]);
    }
  }
  if (ans == 1e18) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
