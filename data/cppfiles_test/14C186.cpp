#include <bits/stdc++.h>
using namespace std;
void solve(long long TEST_CASE) {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n + 1);
  for (long long i = 1; i <= n; i++) cin >> a[i];
  vector<long long> d(n + 1);
  for (long long i = 1; i <= n; i++) d[i] = max((long long)-1, i - a[i]);
  vector<long long> dp(n + 1), p(n + 1);
  for (long long i = 1; i <= n; i++) {
    if (d[i] == -1) continue;
    dp[i] = 1;
    p[i] = i;
    for (long long j = 1; j < i; j++) {
      if (d[j] != -1 && d[j] <= d[i] && (d[i] - d[j]) <= (i - j - 1)) {
        if (dp[i] <= 1 + dp[j]) {
          dp[i] = 1 + dp[j];
          p[i] = j;
        }
      }
    }
  }
  long long in = -1;
  for (long long i = n; i >= 1; i--) {
    if (d[i] != -1 && dp[i] >= k) {
      if (in == -1 || d[in] > d[i]) {
        in = i;
      }
    }
  }
  if (in == -1) {
    cout << "-1" << endl;
    return;
  }
  cout << d[in] << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test_cases;
  cin >> test_cases;
  for (long long i = 1; i <= test_cases; i++) solve(i);
}
