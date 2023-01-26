#include <bits/stdc++.h>
using namespace std;
long long lol;
long long func(string &s, long long i, long long j) {
  long long ind = lol - j - 1;
  if (ind < 0) ind = 0;
  while (j + ind < s.length()) {
    if (s[i + ind] > s[j + ind]) return 1000000007;
    if (s[i + ind] < s[j + ind])
      return ind;
    else {
      ind++;
      lol++;
    }
  }
  return 1000000007;
}
void solve() {
  long long n;
  string s;
  cin >> n;
  cin >> s;
  long long dp[n + 1];
  for (long long i = 0; i < n + 1; i++) dp[i] = 0;
  dp[n] = 1;
  for (long long i = n - 1; i >= 1; i--) {
    lol = i;
    long long t = 0;
    for (long long j = i + 1; j <= n; j++) {
      t = max(t, dp[j] - func(s, i - 1, j - 1));
    }
    dp[i] = n - i + 1 + t;
  }
  sort(dp, dp + n + 1);
  cout << dp[n] << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
