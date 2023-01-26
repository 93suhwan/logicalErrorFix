#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long P = 998244353;
const long long N = 5000 + 10;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    string s;
    cin >> n >> s;
    vector<vector<long long> > lcp(n + 1, vector<long long>(n + 1));
    vector<long long> dp(n + 1);
    for (long long i = n - 1; i >= 0; i--) {
      for (long long j = n - 1; j >= 0; j--) {
        if (i == j)
          lcp[i][j] = n - i;
        else if (s[i] != s[j])
          lcp[i][j] = 0;
        else
          lcp[i][j] = lcp[i + 1][j + 1] + 1;
      }
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      dp[i] = n - i;
      for (long long j = 0; j < i; j++) {
        if (lcp[i][j] < n - i && s[i + lcp[i][j]] > s[j + lcp[i][j]]) {
          dp[i] = max(dp[i], dp[j] + n - i - lcp[i][j]);
        }
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
